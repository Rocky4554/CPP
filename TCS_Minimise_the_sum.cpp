#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;

    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    int k;
    cin>>k;

    priority_queue<int> q;
    int sum=0;
    // for(int i=0;i<n;i++){
    //     sum +=ar[i];
    // }

    for(int i=0;i<n;i++){
        q.push(ar[i]);
    }

    while(k--){

        int t=q.top();
        q.pop();
        int c=ceil(t/2);
       
        q.push(c);

    }
    while(!q.empty()){
        int t=q.top();
        q.pop();
        sum += t;
        
    }

    cout<<sum<<endl;


    return 0;
}