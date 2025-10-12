#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &lin,int &timer,vector<int> adj[]){
    vis[node]=1;
    tin[node]=timer++;
    lin[node]=timer++;
    for(auto it:adj[node]){

        if(it==parent) continue;

        if(vis[it]==0)  {
            dfs(it,node,vis,tin,lin,timer,adj);   
            lin[node]=min(lin[node],lin[it]);
            if(lin[it]>tin[node]){
                cout << node << "-->" << it <<endl;
            }

        }else{
            lin[node]=min(lin[node],tin[it]);
        }
    }

} 

int main()
{
    int n,m;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n;
    cin>>m;

    vector<int> adj[n+1];//total vertices is n
    cout<<"Enter the " <<m<< " edges\n";
    
    for(int i=0;i<m;i++){
        int source,destination;
        cin>>source;
        cin>>destination;
    

    adj[source].push_back(destination);//adding vertics to each other;
    adj[destination].push_back(source);
    }

    vector<int> tin(n+1,-1);
    vector<int> lin(n+1,-1);
    vector<int> vis(n+1,0);
    int timer=0;

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
        dfs(i,-1,vis,tin,lin,timer,adj);
        }
    }

    return 0;
}