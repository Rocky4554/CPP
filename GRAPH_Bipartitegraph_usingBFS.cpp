#include<bits/stdc++.h>
using namespace std;

bool diffcolor(int src,vector<int>adj [],int color[] ){
    queue<int> q;
    q.push(src);
    color[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]= 1-color[node];// here we are actually coloring the adjacent node with color opposite to its parent
                q.push(it);// 1- color[node]=1-0=0(so we are marking it with zero)
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
   
    }
     return true;
}

bool checkbipartite(vector<int> adj[],int n){
    int color[n];// here it will act as both color and visited array
    memset(color,-1,sizeof color);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!diffcolor(i,adj,color)){// this diffcolor is actually our bfs search.
                return false;
            }
        }
    }
    return true;
}



int main(){

    int n,m;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n;
    cin>>m;

    vector<int> adj[n+1];//size is more than total nof vertices.// vector of array
    cout<<"Enter the " <<m<< " edges\n";
    
    for(int i=0;i<m;i++){
        int source,destination;
        cin>>source;
        cin>>destination;
    

    adj[source].push_back(destination);//adding vertics to each other;
    adj[destination].push_back(source);
    }

    if(checkbipartite(adj,n)){// n is no of nodes
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    return 0;
}