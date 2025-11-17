#include<bits/stdc++.h>
using namespace std;

int maxelement(int ar[],int index,int n){
    if(index==n-1){
        return ar[index];
    }
  
    int temp=maxelement(ar,index+1,n);
    if(temp>ar[index]){
        return temp;
    }else{
        return ar[index];
    }
}

int main(){
    int n;
    cin>>n;

    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    cout<<"Max Element "<<maxelement(ar,0,n);
    return 0;
}