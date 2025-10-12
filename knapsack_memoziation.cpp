#include<bits/stdc++.h>
using namespace std;

int knapsack(wt,v,n,cap){
    int dp[n+1]
}

int main(){
    cout<<"Enter the size"<<endl;
    int n;
    cin>>n;
    
    cout<<"Enter the capacity"<<endl;
    int cap;
    cin>>cap;

    int wt[n];
    cout<<"Enter the weights"<<endl;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int v[n];
    cout<<"Enter the values"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Maximum profit"<<endl;
    cout<<knapsack(wt,v,n,cap);

    return 0;

}