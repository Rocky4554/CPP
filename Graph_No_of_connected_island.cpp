#include<bits/stdc++.h>
using namespace std;

void get_island(vector<vector<int>> &adj,vector<vector<bool>> &vis,int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || adj[i][j]==0 || vis[i][j]){
        return;
    }

    vis[i][j]=true;// marking it as visited;

    get_island(adj,vis,i+1,j,n,m);
    get_island(adj,vis,i-1,j,n,m);
    get_island(adj,vis,i,j+1,n,m);
    get_island(adj,vis,i,j-1,n,m);

}

int main(){

    vector<vector<int>> adj= {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
    int n=adj.size();
    int m=adj[0].size();

    vector<vector<bool>> vis(n,vector<bool>(m,false));
    
    int total=0;

    for(int i=0;i<n;i++){  
        for(int j=0;j<m;j++){

            if(adj[i][j]==1 && !vis[i][j]){
            get_island(adj,vis,i,j,n,m);
            total++;
        
            
        } 
    } 


} 

 cout<<"Total no of island :"<< total;

 return 0;
}  