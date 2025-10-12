#include<bits/stdc++.h>
using namespace std;

int main(){

cout<<"no"<<endl;
int n;
cin>>n;

for(int i=1;i<=n;i++){
    for(int j=4;j>=i;j--){
        cout<<" ";
        }
        for(int k=1;k<=i;k++){
            cout<<"*";
        }
    cout<<endl;
    
}


    return 0;
}