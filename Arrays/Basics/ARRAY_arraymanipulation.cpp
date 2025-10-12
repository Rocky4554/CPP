#include<bits/stdc++.h>
using namespace std;

int main(){

int N,M,a,b,k;// N is size of array // M is no of query
cin>>N>>M;// a b c are the query inputs

long arr[N+2];



for(int i=0;i<M;i++){
    cin>>a>>b>>k;
    arr[a] +=k;

    arr[b+1] -=k;
}

long sum=0,ans=0;

for(int i=0;i<N+2;i++){
    sum+=arr[i];
    ans=max(ans,sum);
}

cout<<ans;
    return 0;
}