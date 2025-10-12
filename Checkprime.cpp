#include<bits/stdc++.h>
using namespace std;

int isprime(int n){
    if(n<=1){
        return 0;
    }
    for(int i=2;i<=n/2;i++){// main logic 
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}


int main(){
    cout<<"Enter the no\n";
    int n;
    cin>>n;

    cout<<isprime(n);

 return 0;
}