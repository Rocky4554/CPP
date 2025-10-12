#include<bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm is used to find the shortest path from source to all other vertices in the graph which have non-negative weights.
// It is a greedy algorithm.
//This code for undirected graph
//Time complexity is O(V^2) for adjacency matrix and O(E+V) for adjacency list.
int main() {
    int v, m;
    cout << "Enter the number of vertices and edges\n";
    cin >> v >> m;

    // Adjacency list: vector of vectors containing pairs (destination, weight)
    vector<vector<pair<int, int>>> adj(v + 1);  // Fixed syntax

    cout << "Enter the " << m << " edges (source destination weight)\n";

    int source, destination, weight;

    // Edges input
    for (int i = 0; i < m; i++) {
        cin >> source >> destination >> weight;  // Fixed input syntax
        adj[source].push_back({destination, weight});  // Add edge source -> destination
        adj[destination].push_back({source, weight});  // Add edge destination -> source (undirected)
    }

    int src;
    cout << "Enter the source\n";
    cin >> src;

    // Min heap priority queue: stores (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    vector<int> dist(v + 1, INT_MAX);  // Distance array
    dist[src] = 0;  // Distance to source is 0
    p.push({0, src});  // Push (distance, vertex)

    while (!p.empty()) {
        int prev = p.top().second;  // Vertex with minimum distance
        p.pop();

        // Iterate through neighbors of prev
        for (auto it : adj[prev]) {
            int next = it.first;       // Neighbor vertex
            int nextdist = it.second;  // Edge weight
            if (dist[next] > dist[prev] + nextdist) {
                dist[next] = dist[prev] + nextdist;  // Update distance
                p.push({dist[next], next});          // Push updated distance
            }
        }
    }

    // Fixed: Use src instead of source in output
    cout << "Distance from source " << src << " are\n";
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}