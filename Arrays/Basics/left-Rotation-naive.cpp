#include<bits/stdc++.h>
using namespace std;

void rotation(int ar[],int n){

    int temp=ar[0],i;
 for(i=0;i<n-1;i++){//running till second last element beacuse we have to swap the last element.
        ar[i]=ar[i+1];
        }// shifting array of element one step forward      
        ar[n-1]=temp;// at last swaping last element with first element of array
    
}

void rotate(int ar[],int d,int n){
    for(int i=0;i<d;i++){// calling rotation function by d times because wehave to rotate array by d times.
        rotation(ar,n);
    }
}

void print(int ar[],int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
}

int main(){
    int ar[]={1,2,3};
    int n =sizeof(ar)/sizeof(ar[0]);


    rotate(ar,1,n);

    cout<<"Rotated array"<<endl;
    print(ar,n);

    return 0;
}