#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n;
    cin>>m;

    vector<int> adj[n+1];//size is more than total nof vertices.
    cout<<"Enter the " <<m<< " edges\n";
    
    for(int i=0;i<m;i++){
        int source,destination;
        cin>>source;
        cin>>destination;
    

    adj[source].push_back(destination);//adding vertics to each other;
    adj[destination].push_back(source);
    }

return 0;
}