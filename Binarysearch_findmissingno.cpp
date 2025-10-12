#include<bits/stdc++.h>
using namespace std;

int missing(int ar[],int l,int h,int x){
    
        if(h>l){
            int mid = l-(h-l)/2;
            if(ar[mid]==x || x < ar[mid]){
            return ar[mid];
            }
            else if(ar[mid]<x) {
                return missing(ar,mid+1,h,x);
            }
            else{
            return missing(ar,l,mid-1,x);
            }
        }
    return -1;
}


int main(){

    int ar[]={1,2,3,5,7,8};
    int n =sizeof(ar)/sizeof(ar[0]);
    int l=0;
    int h=n-1;
    int x = 6;

    cout<<"required numbers\n";
    cout<<missing(ar,l,h,x);
 
  return 0;
}
