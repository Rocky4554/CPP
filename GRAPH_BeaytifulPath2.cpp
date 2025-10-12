#include<bits/stdc++.h>
using namespace std;

bool findCycle(int src, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[]) {
    // Mark the node as visited.
    visited[src] = true;

    // Include the current node in the recursion Stack.
    recStack[src] = true;
 
    for (int i : adj[src]) {
        // Back edge exists.
        if (recStack[i] == true) {
            return 1;
        }

        // Visit the unvisited adjacent nodes.
        if (visited[i] == false) {
            if (findCycle(i, visited, recStack, adj)) {
                return true;
            }
        }
    }
    // Remove the current node from the recursion stack.
    recStack[src] = false;
    return false;
}

// Function for doing a depth first search on the graph.
int dfs(int src, vector<int> &freq, string &values, vector<int> adj[]) {
    // Increment the frequency of the character assigned to the current node.
    freq[values[src - 1] - 'a']++;

    // To store the maximum frequency.
    int maxValue = freq[values[src - 1] - 'a'];

    // Iterate through the adjacent nodes.
    for (int i : adj[src]) {
        // Update the maximum value.
        maxValue = max(maxValue, dfs(i, freq, values, adj));
    }

    // Decrement the frequency of the character assingned to the current node.
    freq[values[src - 1] - 'a']--;

    // Return the maximum frequency.
    return maxValue;
}

int maxPathValue(int n, int m,string &values,int node[],int edge[]) {
    // Adjacency list.
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int source=node[i];
        int destination=edge[i];

        adj[source].push_back(destination);//adding vertics to each other;
    }

    int ans = 0;

    // For keeping track of visited nodes.
    vector<bool> visited(n + 1, 0), recStack(n + 1, 0);

    // For storing the frequency of the characters.
    vector<int> freq(26, 0);

    for (int i = 1; i <= n; i++) {
        // Check if a cycle exists.
        if (!visited[i] and findCycle(i, visited, recStack, adj)) {
            return -1;
        }
    }

    // Iterate through all the nodes.
    for (int i = 1; i <= n; i++) {
        fill(freq.begin(), freq.end(), 0);

        // Do a DFS from the current node.
        ans = max(ans, dfs(i, freq, values, adj));
    }
    return ans;
}

int main(){
    int n,m;
    string values;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n;
    cin>>m;
    cout<<"Enter string\n";
    cin>>values;
    int node[m];
    int edge[m];
    cout<<"Enter the first array\n";
    for(int i=0;i<m;i++){
        cin>>node[i];
    }
    cout<<"Enter the second array\n";
    for(int i=0;i<m;i++){
        cin>>edge[i];
    }
    cout<<maxPathValue(n,m,values,node,edge);

return 0;
}