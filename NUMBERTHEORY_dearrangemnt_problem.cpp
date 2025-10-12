#include<bits/stdc++.h>
using namespace std;

const unsigned int mod = 1000000007;

int func(int n){

  if (n == 1) return 0;
  if (n == 2) return 1;
 
  // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
  return ((n - 1) * (func(n - 1) + func(n - 2)))%mod;
}

int main(){
    cout<<"Enter the no: \n";
    int n;
    cin>>n;

    cout<<func(n)<<endl;

return 0;

}