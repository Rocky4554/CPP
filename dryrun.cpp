#include <bits/stdc++.h>
using namespace std;

typedef long long int ll; 
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll N ,M;
        cin>>N>>M;
        
        ll ans=pow((pow(2,N)-1),M);
        cout<<ans<<endl;
    }
    
	// your code goes here
	return 0;
}