#include<bits/stdc++.h>
using namespace std;
int check(int sr[],int n){
    
    if(n==0){
        return 0;
    }
    
    if((sr[0]+sr[2])==2*sr[3]){
        return (1+check(sr,n-1));
    }
    
    else{
        return check(sr,n-1);
    }

    
}

int main(){
    cout<<"size"<<endl;
    int n;
    cin>>n;

    int sr[n];
    cout<<"enter values in array";
    for(int i=0;i<n;i++){
        cin>>sr[i];
    }
    cout<<check(sr,n);

    return 0;
}