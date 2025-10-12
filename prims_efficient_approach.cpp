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

    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >  q;
    q.push(make_pair(0,0));//inserting (key as 0 of index i,index of i)(i is source index)

    for(int i=0;i<v-1;i++){
        int u=q.top().second;
        q.pop();

        vis[u]=true;
        for(auto it:adj[u]){
            int v=it.first;      
            int weight=it.second;
            if(vis[v]==false && key[v]>weight){
                parent[v]=u;
                q.push({key[v],v});
                key[u]=weight;


            }
        }


    }
    for(int i=1;i<v;i++){
        cout<<parent[i]<<"-->"<< i<< "\n";  
    } 

    return 0;
}