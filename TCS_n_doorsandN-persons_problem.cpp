#include<iostream>
using namespace std;

void solve(int n){
    int ar[n];
    for(int i=1;i<=n;i++){
        ar[i]=i;
    }
    int vis[n]={0};int m=1;
    while(m<n){
        for(int i=1;i<=n;i++){
            if(i%m==0){
                if(vis[i]==0){
                    vis[i]=1;
                }
                else {
                    vis[i]=0;
                }
            }
        }
        m++;
       
        
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            cout<<"closed"<<" ";
        }else{
            cout<<"open"<<" ";
        }
    }
}

int main(){

    int n;
    cin>>n;

    solve(n);

    return 0;
}