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

        const int N=1e6+2;
        int idx[N];
        for(int i=0;i<N;i++){
            idx[i]=-1;

        }

        int minidx=INT_MAX;

        for(int j=0;j<n;j++){
         if(idx[ar[j]] != -1){
             minidx=min(minidx,idx[j]);

         }
         else{
             idx[ar[j]]=j;
         }

        }
        if(minidx==INT_MAX){
         cout<<"-1"<<endl;

        }
        else{
            cout<<minidx+1<<endl;
        }
        return 0;
}
