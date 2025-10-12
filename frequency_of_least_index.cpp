#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"enter the size"<<endl;
    int n;
    cin>>n;

    int ar[n];
    cout<<"enter the array"<<endl;
    for(int i=0; i<n;i++){
        cin>>ar[i];
        }

        int N=1e6;
        int idx[N];
        for(int i=0;i<N;i++){
            idx[i]=-1;

        }

        int minidx=INT_MAX;

        for(int i=0;i<n;i++){
         if(idx[ar[i]] != -1){
             minidx=min(minidx,idx[ar[i]]);

         }
         else{
             idx[ar[i]]=i;
         }

        }
        if(minidx==INT_MAX){
         cout<<"-1"<<endl;

        }
        else{
            cout<<ar[minidx]<<endl;
        }
        return 0;
}
