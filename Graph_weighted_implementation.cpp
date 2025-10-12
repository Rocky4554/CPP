#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,m;
    cout<<"Enter the no of vertices and edges\n";
    cin>>v;
    cin>>m;

    vector<pair<int,int>> adj[v+1];//size is more than total nof vertices.
    cout<<"Enter the " <<m<< " edges\n";
    
    for(int i=0;i<m;i++){
        int source;
        int destination;
        int weight;
        cin >> source;
        cin >> destination;
        cin >> weight;// taking weight input

        adj[source].push_back(make_pair{destination,weight});//adding vertices  as well as weight;
        adj[destination].push_back(make_pair{source,weight});
  
    }

    return 0
}