#include<bits/stdc++.h>
using namespace std;
// same as count of subset with diff equal to 1.

int totalways(int ar[],int n,int sum)
{
int s[n+1][sum+1];//change bool to int
    for(int i =0;i<n+1;i++)//if sum is zero for all n then empty set is possible
        s[i][0]=true;
        for(int i=0;i<sum+1;i++)//if ther is no number then no set is possible for sum
            s[0][i]=false;
    //printing the s[][] for subset sum.
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(ar[i-1]>sum){
                s[i][j]=s[i-1][j];

            }
           else{
                s[i][j]=s[i-1][j-ar[i-1]] + s[i-1][j]; //only changing"||"to "+"" to get total subset.
        }
    }

    }
    return s[n][sum];

}


int main()
{
    int ar[]={1,1,1,1,1};
    int n =sizeof(ar)/sizeof(ar[0]);
    int req_sum= 1;// equal to "diff" in count of subset with diff equal to 1;
        int res =0;
    for(int i=0;i<n;i++)
        res += ar[i];

    int sum =(res+req_sum)/2;// use the same formula.
    cout<<"total ways is:\n";
    cout<<totalways(ar,n,sum);
    
    return 0;
}
