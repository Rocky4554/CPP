#include<bits/stdc++.h>
using namespace std;

total(int n, int coins[],int tm,vector<vector<int>> &dp){
    if(tm==0){
        return dp[n][tm]=1;

    }
    if(n==0){
        return 0;
    }
    if(dp[n][tm] !=-1){
        return dp[n][tm];
    }
    if(coins[n-1]<=tm){
        return dp[n][tm]= total(n,coins,tm-coins[n-1],dp) + total(n-1,coins,tm,dp);
    }
    else{
        return dp[n][tm]=total(n-1,coins,tm,dp);
    }


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

    vector<vector<int>> dp(n+1,vector<int>(tm+1,-1));// we are creating a 2d array for memoization.

    cout<<total(n,coins,tm,dp);
    return 0;
}