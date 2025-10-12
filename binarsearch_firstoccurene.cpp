#include<bits/stdc++.h>
using namespace std;

int missing(int ar[],int l,int h,int x){
    
        while(h>=l){
            int mid =(l+h)/2;
            if((mid ==0 || ar[mid]<x) && ar[mid]==x ){
            return mid;
            }
            else if(x>ar[mid]) {
                return missing(ar,(mid+1),h,x);
            }
            else{
            return missing(ar,l,(mid-1),x);
            }
        }
    return -1;
}


int main(){

    int ar[]={1,3,3,4,4,5,5,5,7,8,8};
    int n =sizeof(ar)/sizeof(ar[0]);
    int l=0; 
    int h=n-1;
    int x = 5;

    cout<<"required numbers\n";
    cout<<missing(ar,l,h,x);
 
  return 0;
}
