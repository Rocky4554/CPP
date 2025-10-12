#include<bits/stdc++.h>
using namespace std;

int total(int n,int coins[],int tm){

    vector<vector<int>> dp(n+1,vector<int>(tm+1));

    int i,j;
    
    for(i=1;i<=tm;i++)// if there is no coin
        dp[0][i]=0;
    
    for(i=0;i<=n;i++)//if the amount is only zero
        dp[i][0]=1;
    

    for( i=1;i<=n;i++){
        for(j=1;i<=tm;j++){
            if(j>=coins[i-1]){
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][tm];

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

    

    cout<<total(n,coins,tm);

    return 0;
}