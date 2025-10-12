#include<bits/stdc++.h>
using namespace std;

int rotation(int ar[],int n){

    int l=0,h=n-1;

    while(l<h){

        int mid = l+(h-l)/2;

        if(ar[mid] <= ar[mid-1] && ar[mid] <= ar[mid +1] && ar[mid]>0){ // the smallest no will be always smaller than the no both sides of it
            return ar[mid];
        }
        if(ar[l]<=ar[mid] && ar[mid]>ar[h]){// we always have to search in unsorted part not in sorted part
            l= mid+1;
        }else{

            h = mid -1;
        }

        }

        return ar[l];
    }

int main(){

    int ar[]={11,13,15,17};
    int n =sizeof(ar)/sizeof(ar[0]);

    cout<<"no of times rotated :"<< rotation(ar,n);

    return 0;
}
