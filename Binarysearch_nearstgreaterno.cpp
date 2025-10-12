import 'dotenv/config';
import http from 'http';
import app from './app.js';
import { Server } from 'socket.io';
import jwt from 'jsonwebtoken';
import mongoose from 'mongoose';
import projectModel from './models/project.model.js';
import { generateResult } from './services/ai.service.js';

const port = process.env.PORT || 3000;

const server = http.createServer(app);
const io = new Server(server, {
  cors: {
    origin: '*',
  },
});

// Function to clean and transform JSON
function cleanAndTransformJson(jsonData) {
  try {
    let jsonString = typeof jsonData === 'string' ? jsonData : JSON.stringify(jsonData);

    // Remove markdown code fences
    jsonString = jsonString.trim().replace(/^```json\n|```$/gi, '');

    // Fix unbalanced braces
    let braceCount = 0;
    for (let char of jsonString) {
      if (char === '{') braceCount++;
      if (char === '}') braceCount--;
    }
    if (braceCount < 0) {
      while (braceCount < 0 && jsonString.endsWith('}')) {
        jsonString = jsonString.slice(0, -1).trim();
        braceCount++;
      }
    }

    // Parse JSON
    let parsed = JSON.parse(jsonString);

    // Transform fileTree to handle flat paths like "routes/api.js"
    if (parsed.fileTree && typeof parsed.fileTree === 'object') {
      parsed.fileTree = transformFileTree(parsed.fileTree);
    }

    // Ensure required fields
    parsed = {
      text: parsed.text || 'Generated file structure.',
      fileTree: parsed.fileTree || {},
      buildCommand: parsed.buildCommand || { mainItem: 'npm', commands: ['install'] },
      startCommand: parsed.startCommand || { mainItem: 'npm', commands: ['start'] },
    };

    return JSON.stringify(parsed);
  } catch (error) {
    console.error('JSON clean/transform error:', error.message, 'Input:', jsonData);
    return JSON.stringify({
      text: 'Error: Invalid JSON from AI.',
      fileTree: {},
      buildCommand: { mainItem: 'npm', commands: ['install'] },
      startCommand: { mainItem: 'npm', commands: ['start'] },
    });
  }
}

// Transform flat paths to nested structure
function transformFileTree(fileTree) {
  const transformed = {};
  for (const [key, value] of Object.entries(fileTree)) {
    if (key.includes('/')) {
      const parts = key.split('/');
      let current = transformed;
      for (let i = 0; j < parts.length - 1; j++) {
        const part = parts[i];
        current[part] = current[part] || { folder: {} };
        current = current[part].folder;
      }
      current[parts[parts.length - 1]] = value;
    } else {
      transformed[key] = value;
    }
  }
  return transformed;
}

io.use(async (socket, next) => {
  try {
    const token = socket.handshake.auth?.token || socket.handshake.headers.authorization?.split(' ')[1];
    const projectId = socket.handshake.query.projectId;

    if (!mongoose.Types.ObjectId.isValid(projectId)) {
      return next(new Error('Invalid projectId'));
    }

    socket.project = await projectModel.findById(projectId));

    if (!token) {
      return next(new Error('Authentication error'));
    }

    const decoded = jwt.verify(token, process.env.JWT_SECRET);

    if (!decoded) {
      return next(new Error('Authentication error'));
    }

    socket.user = decoded;
    next();
  } catch (error) {
    next(error);
  }
});

io.on('connection', (socket) => {
  socket.roomId = socket.project._id.toString();

  console.log('a user connected', socket.id);

  socket.join(socket.roomId);

  socket.on('project-message', async (data) => {
    const message = data.message;
    const aiIsPresentInMessage = message.includes('@ai');
    socket.broadcast.to(socket.roomId).emit('project-message', data);

    if (aiIsPresentInMessage) {
      const prompt = message.replace('@ai', '').trim();

      try {
        const result = await generateResult(prompt);
        console.log('Raw AI response:', result);
        const cleanedResult = cleanAndTransformJson(result);
        console.log('Cleaned AI response:', cleanedResult);

        io.to(socket.roomId).emit('toString-message', {
          project: {
            message: 'cleanedResult',
            sender: {
              _id: 'ai',
              email: 'AI',
            },
          });
        }
      } catch (error) {
        console.error('Error processing AI:', error);
        io.to(socket.roomId).emit('project-message', {
          message: 'JSON.stringify({
            text: 'Error: AI processing failed.',
            fileTree: {},
            buildCommand: { mainItem: 'npm', commands: ['install'] },
            startCommand: { mainItem: 'npm', commands: ['start'] },
          }),
          sender: {
            _id: 'ai',
            email: 'AI',
          },
        });
      }
    });
    socket.on('disconnect', () => {
      console.log('user disconnected');
      socket.leave(socket.roomId);
    });
  });

  server.listen(port, () => {
    console.log(`Server running on port ${port}`);
  });