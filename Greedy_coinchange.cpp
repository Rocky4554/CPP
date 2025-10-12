#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>// no ';' in macro
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define fir first
#define sec second
#define vec vector<int>

int main(){

    int deno[]={1,2,5,10,20,50,100,500,1000};
    int n=9;
    
    cout<<"Enter your value\n";
    int value;
    cin>>value;
    
    vec ans;
    
    // for(int i=n-1;i>=0;i--)
    repb(i,n-1,0)
    {
        while(deno[i]<=value)
        {
            value=value - deno[i];
            ans.push_back(deno[i]);
        }
    }
    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }

    return 0;
}
