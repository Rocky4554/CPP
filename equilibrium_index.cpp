#include<bits/stdc++.h>
using namespace std;

int sum(int ar[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += ar[i];
    }
    return sum;
}

int equilibrium(int ar[],int n){
    int leftsum=0;
    int totalsum = sum(ar,n);

    for(int i=0;i<n;i++){
        totalsum -= ar[i];//our right sum.

        if(leftsum==totalsum){
        return i;
        }

        leftsum += ar[i];// left sum.
    }
    return -1;
}

int main(){

int ar[]={-7,1,5,2,-4,3,0};
int n=sizeof(ar)/sizeof(ar[0]);

cout<<"our equilibrium index\n";
cout<<equilibrium(ar,n);

    return 0;
}