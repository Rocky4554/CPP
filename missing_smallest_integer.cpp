#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"enter the size of array\n";
    int n;
    cin>>n;

    int ar[n];
    cout<<"enter the array\n";
    for(int i=0; i<n ;i++){
        cin>>ar[i];
    }

    int N=1e6;
    bool sr[N];

    for(int i=0; i<n;i++){
    if(ar[i]>=0){
        sr[i]=true;

    }
    else{
        sr[i]=false;
    }

    }

    for(int i=0; i<N; i++){
    if(sr[i]==false){
        cout<<i<<endl;
        break;
    }
    }




    return 0;
}
