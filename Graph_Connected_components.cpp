#include<bits/stdc++.h>
using namespace std;

vector<bool> vis;//global
int n,m;
vector<vector<int>> adj;//vector<vector<int>> adj[n];//glovbal

vector<int> components;//global

int get_comp(int idx){
    if(vis[idx]){
        return 0;
    }
    
    vis[idx]=true;
    int ans = 1 ;

    for(auto i:adj[idx]){
        if(!vis[i]){
            ans +=get_comp(i);
            vis[i]=true;
        }
    }
    return ans;
}

int main(){

cin>>n>>m;

adj = vector<vector<int>>(n);
vis= vector<bool>(n,0);

for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int total=0;
for(int i=0;i<n;i++){
    if(!vis[i]){
        components.push_back(get_comp(i));
        total++;
    }
}

for(auto i:components){
    cout<<i<<" ";
}
cout<<endl;
cout<<"total no of components :"<<total;

return 0;
    
}