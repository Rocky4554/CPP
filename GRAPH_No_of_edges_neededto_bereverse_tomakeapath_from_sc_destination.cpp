#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+10;

vector<pair<int,int>> adj[N];
vector<int> level(N,INF);// like dikstra algo filling with infinity initiallly
int v,e;

int bfs(){
    deque<int> q;  
    q.push_back(1);// pushing the source;we can take user input also
    level[1]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop_front();
 
        for(auto &it:adj[curr]){  
            int child=it.first;
            int weight=it.second;
            if(level[curr] + weight < level[child]){
                level[child]=level[curr] + weight;
            }  
            if(weight==0){
                q.push_front(child);//if src to adjacent edge weight is 0 then push it in front of queue
            }else{
                q.push_back(child);//if src to adjacent edge weight is 1 then push it in back of queue
            }

        }
    }
    return level[v] == INF ? -1: level[v];
}

int main(){
cin>>v>>e;
cout<<"Enter the edegs"<<endl;
for(int i=0;i<e;++i){
    int x,y;
    cin>>x>>y;
    if(x==y){// if self loop then ignore
        continue;
    }

    adj[x].push_back({y,0});
    adj[y].push_back({x,1});
}

cout<< bfs <<endl;

return 0;
}
