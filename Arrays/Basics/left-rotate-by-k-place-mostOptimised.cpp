#include<bits/stdc++.h>
using namespace std;
   
void reverse(int ar[],int s,int e){
    while(s<e)
    {
    int temp=ar[s];
    ar[s]=ar[e];
    ar[e]=temp;
    s++;
    e--;
    }
        
}
void rotate(int ar[], int k,int n) {
    k=k % n;
    
    reverse(ar,0,k-1);//then from reversed array reversing first k element
    reverse(ar,k,n-1);// then from result above reversing the remaining elements .
    reverse(ar,0,n-1);// reversing whole array
    
    
}

int main(){

    int ar[]={2,3,4,1,5,2};
    int n=sizeof(ar)/sizeof(ar[0]);
    int k=2;

    rotate(ar,k,n); 
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}