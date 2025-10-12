#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int v){
    vector<bool> vis(v+1,false);
    // vectot<int> ans;

    for(int i=1;i<=v;i++){
        if(vis[i]==false){

            queue<int> q;    
            q.push(i);     
            vis[i]=true;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                // ans.push_back(node);
                cout<< node <<" ";   
 
                for(auto it: adj[node]){
                    if(vis[it]==false){
                        q.push(it);
                        vis[it]=true;
                    }
                }

            }
        }

    }    
    

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
    cout<<"Our bfs traversal is \n";
    bfs(adj,v);
    

    return 0;
}   