#include<bits/stdc++.h>
using namespace std;

bool diffcolor(int src,vector<int>adj [],int color[] ){
   if(color[src]==-1){// first time when we are calling the color of starting node is -1
       color[src]=1;
   }
   for(auto it:adj[src]){
       if(color[it]==-1){
           color[it]=1-color[src];//we are marking the adjacent with diff color
           if(!diffcolor(it,adj,color)){// here we are again calling the dfs for the adj node making it as a parent node
               return false;
           }
       }
       else if(color[it]==color[src]){
           return false;
       }

   }return true;
}

bool checkbipartite(vector<int> adj[],int n){
    int color[n];// here it will act as both color and visited array
    memset(color,-1,sizeof color);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!diffcolor(i,adj,color)){// this diffcolor is actually our dfs search.
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