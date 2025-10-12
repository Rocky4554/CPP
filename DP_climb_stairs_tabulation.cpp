#include<bits/stdc++.h>
using namespace std;

int climb(int n){
    int dp[n+1];

    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i==1){
            dp[i]=dp[i-1];
        }else{
            dp[i]=dp[i-1]+dp[i-2];
        }
        
    }
    return dp[n];
}


int main(){

int n;
cout<<"Enter the no of stairs\n";
cin>>n;
//he is alllowed to take only 1 or 2 steps at a time.

cout<<climb(n);


    return 0;
}