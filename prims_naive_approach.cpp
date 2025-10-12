#include<bits/stdc++.h>
using namespace std;

int main(){

    int v,m;
    cout<<"Enter the no of vertices and edges\n";
    cin>>v;
    cin>>m;

    vector<pair<int,int>> adj[v];//size is more than total nof vertices.
    cout<<"Enter the " <<m<< " edges\n";
    
    int source;
    int destination;
    int weight;

    for(int i=0;i<m;i++){
        
        cin >> source;
        cin >> destination;
        cin >> weight;// taking weight input

        adj[source].push_back(make_pair(destination,weight));//adding vertices  as well as weight;
        adj[destination].push_back(make_pair(source,weight));
  
    }

    int parent[v];
    int key[v];
    bool vis[v];

    for(int i=0;i<v;i++){
     vis[i]=false, key[i]=INT_MAX;// here in key we are taking INT_MAX bcause we
         //have to initialize all the key with maximum value execepth the first one with zero;
    }

    parent[0]=-1;
    key[0]=0;

    for(int i=0;i<v-1;i++){// running till total no of edges;//  this loop is for traversing over each vertics
        int miniweight=INT_MAX,u;

        for(int j=0;j<v;j++)//this loop for taking out the minimal key.(we remove this loop with priority queue in efficient approach )
            if(vis[j]==false && key[j]<miniweight)
                miniweight=key[j],u=j;
                vis[u]=true;

        for(auto it:adj[u]){// this loop is for checking eacj adjacent vertices of each vertices
                int k=it.first;
                int weight=it.second;

            if(vis[k]==false &&  weight<key[k]){
                    key[k]=weight,parent[k]=u;
            }
                
        }

            
    }   

    for(int i=1;i<v;i++){
        cout<<parent[i]<<"-->"<< i<< "\n";  
    }  
        
    
    return 0;
}