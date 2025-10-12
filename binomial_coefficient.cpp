#include<bits/stdc++.h>
using namespace std;
int binomial(int n ,int r){ // "nCr"
    int ans =1;
    if(r>n)
    r= n-r;
    for(int i=0;i<r;i++){ // loop will run till 'r'.
        ans = ans*(n-i);
        ans = ans/(i+1);
    }
    return ans;
}

int main(){
  cout<<"enter N\n";
  int n;
  cin>>n;

  cout<<"enter r\n"; 
  int r;
  cin>>r;

  cout<<"binomial  factorial:\n";
  cout<<binomial(n,r);

    return 0;
}