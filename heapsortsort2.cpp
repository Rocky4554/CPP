#include<bits/stdc++.h>
using namespace std;


void heapify(int ar[],int n,int i){
    int largest=i;
    int l=2*i;
    int r=2*i+1;
if(l<=n && ar[l]> ar[largest] ){


    largest =l;
}


if( r<=n && ar[r]>ar[largest]){
    largest = r;
}

if(largest!=i){
swap(ar[i],ar[largest]);
heapify(ar,n,largest);
}

}



void heapsort(int ar[], int n){
//  int heapsize=n;
 for(int i=n/2;i>=1;i--){
    heapify(ar,n,i);
 }

    for(int i=n; i>2;i--){
        swap(ar[1],ar[i]);
        // heapsize -=1;
        heapify(ar,i,1);
        
    }
}

void print(int ar[],int n){
    for(int i=1;i<=n;i++)
    cout<<ar[i]<<" ";
    cout<<"\n";
}

int main(){
    cout<<"enter the size\n";
    int n ;
    cin>>n;

    int ar[n];
    cout<<"enter the values in array\n";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    heapsort(ar,n);
    cout<<"sorted array\n";
    print(ar,n);

    return 0;
}