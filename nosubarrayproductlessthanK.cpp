#include<bits/stdc++.h>
using namespace std;

int noofsubarray(int *ar,int n ,int k){//using sliding window technique.
    if(k<=1) return 0;
    int prod=1;
    int result=0;

    int left=0;// start point of window.
    int right=0;// end point of window.

    while(right<n){
        prod *= ar[right];

        while(prod>=k){
            prod /=ar[left];
            left++;
        }
        result += right - left +1;
        right++;
    }
    return result;
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

cout<<"No of subarray of product less than k \n";
cout<<noofsubarray(ar,n,k);

return 0;
}