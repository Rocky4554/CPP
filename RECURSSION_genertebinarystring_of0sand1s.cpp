#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    int oczero=1;
    int ocone=1;

    for(int i=2;i<=n;i++){
        int nczero=ocone;
        int ncone=oczero+ocone;

        oczero=nczero;
        ocone=ncone;
    }
    cout<<(ocone+oczero);
       
}


int main(){
cout<<"Enter the no\n";
int n;
cin>>n;

cout<<"total binary strings\n";
solve(n);


    return 0;
}