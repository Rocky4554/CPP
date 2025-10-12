#include<bits/stdc++.h>
using namespace std;

void dfshelp(int node,vector<bool> &vis,vector<int> adj[],vector<int> &ans){

    ans.push_back(node);
    vis[node]=true;
    for(auto it:adj[node]){
        if(vis[it]==false){
            dfshelp(it,vis,adj,ans);
        }   
    }

}

vector<int> dfs(vector<int> adj[],int v){
    vector<int> ans;
    vector<bool> vis(v,false);

    for(int i=1;i<=v;i++){
        if(vis[i]==false)
        dfshelp(i,vis,adj,ans);
    }

    return ans;

}

int main(){       
    int v,m;
    cout<<"Enter the no of vertices and edges\n";
    cin>>v;
    cin>>m;

    vector<int> adj[v+1];//size is more than total nof vertices.
    cout<<"Enter the " <<m<< " edges\n";
    
    for(int i=0;i<m;i++){
        int source;
        int destination;
        cin >> source;
        cin >> destination;

        adj[source].push_back(destination);//adding vertics to each other;
        adj[destination].push_back(source);
  
    }
    
    vector<int> result=dfs(adj,v);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    cout<<endl;

    return 0;
}