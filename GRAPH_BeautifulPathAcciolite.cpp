#include<bits/stdc++.h>
using namespace std;

bool dfs(int vertex,vector<int> &vis,vector<int> adj[],vector<int> &letter,int arr[][26]){
    vis[vertex]=1;
    for(auto it:adj[vertex]){
        if(vis[it]==1)
            return true;// cycle present;
        if(vis[it]==0 && dfs(it,vis,adj,letter,arr)) 
            return true;// loop present;
        for(int i=0;i<26;i++ ){
            arr[vertex][i]=max(arr[vertex][i],arr[it][i]);
        }
        
    }
    arr[vertex][letter[vertex]]++;
    vis[vertex]=2;

    return false;
}

int main(){
    int n,m;
    string s;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n;
    cin>>m;
    cout<<"Enter string\n";
    cin>>s;
    int node[m];
    int edge[m];
    cout<<"Enter the first array\n";
    for(int i=0;i<m;i++){
        cin>>node[i];
    }
    cout<<"Enter the second array\n";
    for(int i=0;i<m;i++){
        cin>>edge[i];
    }
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int source=node[i];
        int destination=edge[i];

        adj[source].push_back(destination);//adding vertics to each other;
    }
    vector<int> letter(n+1);
    vector<int> vis(n+1);
    int arr[n+1][26];
    for(int j=1;j<=n;j++){
        letter[j]=s[j-1]-'a';
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0 && dfs(i,vis,adj,letter,arr)){
            cout<<"-1";
        }
        int answer=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<26;j++){
                answer=max(answer,arr[i][j]);
            }
        }
        cout<<answer;
    }

return 0;
}