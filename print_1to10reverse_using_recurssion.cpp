#include<bits/stdc++.h>
using namespace std;

void print(int n){
    if(n>0){//(n>=0)if we have to print till zero.
        cout<<n<<" ";
        print(n-1);
    }
}

int main(){
    int n;
    cout<<"enter the no\n";
    cin>>n;

    print(n);

    return 0;
}