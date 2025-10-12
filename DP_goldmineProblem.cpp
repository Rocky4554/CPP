#include<bits/stdc++.h>
using namespace std;

int digpoint(int ar[][6],int m, int n){

    int dp[n][m];
    for(int j=n-1;j>=0;j--){
        for(int i=m;i>=0;i--){
            if(j==n-1){
                dp[i][j]=ar[i][j];
            }
            else if(i==0){
                dp[i][j]= ar[i][j]+ max(dp[i][j+1],dp[i+1][j+1]);
            }
            else if(i==m-1){
                dp[i][j]= ar[i][j]+ max(dp[i][j+1],dp[i-1][j+1]);
            }
            else{
                dp[i][j]= ar[i][j]+ max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1]));
            }
        }
    }
    int maxx=dp[0][0];
    for(int i=1;i<m;i++){
        if(dp[i][0]>maxx){
            maxx=dp[i][0];
        }
    }

    return maxx;
}

int main(){
int m=6;
int n=6;
int ar[6][6]={{0,1,4,2,8,2},{4,3,6,5,0,4},{1,2,4,1,4,6},{2,0,7,3,2,2},{3,1,5,9,2,4},{2,7,0,8,5,1}};


// cout<<"Enter the no of elements in a array/n";
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//             cin>>ar[i][j];
//     }
// }
cout<<"The point of start digging is : "<<digpoint(ar,m,n)<<endl;

return 0;
}