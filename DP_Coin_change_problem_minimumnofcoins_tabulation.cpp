#include<bits/stdc++.h>
using namespace std;

int coinChange(int n,int coins[],int tm){

    int dp[n+1][tm+1];
    

    for(int i=0;i<=n;i++){
        for(int j=0;j<=tm;j++){

            if(j==0){
                dp[i][j]=0;
            }
            else if(i==0){
                dp[i][j]=1e5;
            }

        else if(coins[i-1]>j){
            dp[i][j]=dp[i-1][j];
        }
        else{
            dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
        }
    }
    }

    return dp[n][tm]>1e4 ? -1:dp[n][tm];
}

int main(){

    int n;
    cout<<"Enter the size\n";
    cin>> n;

    int coins[n];
    cout<<"Enter the coins\n";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int tm;
    cout<<"Enter the total amount\n";
    cin>>tm;

    cout<<coinChange(n,coins,tm);

    return 0;
}