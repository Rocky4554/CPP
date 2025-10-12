#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n;
    cin>>m;

    vector<int> adj[n+1];
    cout<<"Enter the " <<m<< " edges\n";
    int source,destination;
    for(int i=0;i<m;i++){
        cin>>source;
        cin>>destination;
    }

    adj[source].push_back(destination);//adding vertics to each other;
    adj[destination].push_back(source);

return 0;
}