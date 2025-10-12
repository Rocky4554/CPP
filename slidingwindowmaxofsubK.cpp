#include<bits/stdc++.h>
using namespace std;

int maxofsub(int *ar,int n,int k){
    int max_sum=INT_MIN;
    for(int i=0;i<n-k+1;i++){//formula till i will rum (n-k+1).
        int sum=0;
        for(int j=0;j<k;j++){// j will run till k.
            sum += ar[i+j];
        }
        max_sum=max(max_sum,sum);
    }
    return max_sum;
}

int main(){
    
cout<<"Enter the size\n";
int n;
cin>>n;

int ar[n];
cout<<"Enter the vaues in array\n";
for (int i = 0; i <n ;i++)
{
    cin>>ar[i];
}

cout<<"Enter the values of k\n";
int k;
cin>>k;

cout<<"maximum of sum of all subarray of size  k \n";
cout<<maxofsub(ar,n,k);

    return 0;
}