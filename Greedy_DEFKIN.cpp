#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vec vector<int>


int main(){
    cout<<"Enter the width ,length,no of towers\n";
    long long int w,h,n;// taking width and length and no of towers
    cin>>w>>h>>n;

    vec x,y;// crating a vector to ans the coordinates
    
    cout<<"Enter the coordinates of tower\n";
    rep(i,0,n){
        ll wi ,hi;//taking our coordinates
        cin>>wi>>hi;

    x.push_back(wi);//pusing the coordinates in vector
    y.push_back(hi);

    }
    x.push_back(w);//important (pushing last row and col in vector)
    x.push_back(h);

    sort(x.begin(),x.end());//sorting both the vectors
    sort(y.begin(),y.end());

    int maxwidth=x[0]-1;
    int maxlength=y[0]-1;

    rep(i,0,n){
        if(maxwidth<(x[i]-x[i-1]-1)){
            maxwidth=x[i]-x[i-1]-1;
        }
        if(maxlength<(y[i]-y[i-1]-1)){
            maxlength=y[i]-y[i-1]-1;
        }
    }

    ll ans=maxwidth*maxlength;//taking product of largest width and length;

    cout<<"largest unprotected area\n";
    cout<<ans;

    return 0;

}