#include<bits/stdc++.h>
using namespace std;

int find(int ar[],int n){
    int dp[n];
    dp[n-1]=0;
    memset(dp,INT_MAX,sizeof(dp));

    for(int i=n-2;i>=0;i--){
        int minn=INT_MAX;
        for(int j=i+1;j<=min(n-1,i+ar[i]);j++){// to keep j before i when traversing array from backward
            minn = min(j,minn);
        }
        if(minn!=INT_MAX){
            dp[i]=minn+1;
        }
    }

    return dp[0];

}


int main(){

    int ar[]={2,3,0,1,4};
    int n =sizeof(ar)/sizeof(ar[0]);

     cout<<"no of jumps to reach end : "<<find(ar,n)<<endl;

    return 0;
}