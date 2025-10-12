#include<bits/stdc++.h>
using namespace std;

void deletion(int ar[],int target,int n,int pos){
    for(int i=pos;i<n;i++){
        
    }

}

void find(int ar[],int target,int n){
    for(int i=0;i<n;i++){
        ar[i]==target;
        int pos=i;
        delete(ar,target,n,pos);
    }

    cout<<"Element is not present,so deletion is not possible"<<endl;
}

int main(){
int n;
int ar[n];
  
for(int i=0;i<n;i++){
    cin>>ar[i] ;
}

int target;
cin>>target;

cout<<find(ar,target,n);

 return 0;

}