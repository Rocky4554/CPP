#include<bits/stdc++.h>
using namespace std;

void solve(int ar[],int n){
    int l=INT_MIN,sl=INT_MIN;
    for(int i=0;i<n;i++){
        if(ar[i]>l){
            sl=l;
            l=ar[i];
            
        }
        else if(ar[i] <l){
            if(ar[i]>sl)
            sl=ar[i]; 
        }
    }
    cout<<"largest :"<<l<<" second largest :"<<sl<<endl;
}

int main(){

    int n;
    cin>>n;

    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    solve(ar,n);
    return 0;
}

