#include<bits/stdc++.h>
using namespace std;

typedef long long int  ll;

int main(){

    ll g, p;
    cin>>g,p;
    ll ar[10];
    for(ll i=1;i<=10;i++){
        cin>>ar[i];
    }
    ll sum=0;

    for(ll i=g+1;i<=10;i++){
        sum += ar[i];
    }
    
        cout<<"sum"<<sum<<endl;
        ll ans=(sum/p)+((sum%p)!=0);

        cout<<"ans"<<ans<<endl;
        

     cout<<ans+1<<" "<<ans+ar[g-1]<<endl;

    return 0;
}