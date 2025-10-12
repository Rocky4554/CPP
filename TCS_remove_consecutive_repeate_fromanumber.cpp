#include<bits/stdc++.h>
using namespace std;

int remove(int n){
    int pd=n%10;

    int pow=10;

    int r=pd;

    while(n){
        int cr=n%10;
        if(cr!=pd){
            r = r + (pow*cr);
            pd=cr;
            pow=pow* 10;
        }
        n = n/10;
    }

    return r;
}

int main(){

    int n;
    cin>>n;

    cout<<remove(n);

    return 0;
}