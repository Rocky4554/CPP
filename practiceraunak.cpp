#include<bits/stdc++.h>
using namespace std;

void dell(int inputarray[],int n,int i){
    for (int j = i; j < n-1; j++) {
        inputarray[j] = inputarray[j + 1];
        i--;n--;
}
}

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

int solve(int ar[],int ar1[],int n,int m){
    int count=0,count1=0;int i=0;
    while(i<n){
    if(ar[i]==ar1[i]){
        count++;
        i++;
        dell(ar,n,i);
        dell(ar1,n,i);

    }else{
        
        rotate(ar,1,n);
        count1++;
        // j++;
    }

    }
    return count+count1;

}


int main(){
int ar[]={1,3,2};int ar1[]={2,3,1};
int n=sizeof(ar)/sizeof(ar[0]);
int m=sizeof(ar1)/sizeof(ar1[0]);

cout<<solve(ar,ar1,n,m)<<endl;


    return 0;
}