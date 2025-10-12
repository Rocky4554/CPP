#include<bits/stdc++.h>
using namespace std;

void print(int n){
    if(n>0){
        print(n-1);
        cout<<n<<" ";
    }
}

int main(){
    int n;
    cout<<"enter the no\n";
    cin>>n;

    print(n);
  return 0;
}