#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define pii pair<int,int>// no ';' in macro
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fir first
#define sec second
#define vec vector<int>

typedef int i;

bool camparator(pii p1,pii p2){
    double v1 =(double) p1.fir/p1.sec;
    double v2 =(double) p2.fir/p2.sec;

    return v2 > v1;

}

int main(){
    cout<<"Enter the size\n";
    i n;
    cin>>n;

    vii arr(n);//first is weight and second is value;

    cout<<"Enter the weight\n";
    i w;
    cin >> w;

    cout<< "Enter the weight and value of items"<<endl;
    rep(i,0,n){
        cin >>arr[i].fir>>arr[i].sec;

    } 
    sort(arr.begin(),arr.end(),camparator);

    int ans=0;vec selected;
    rep(i,0,n){
        if(arr[i].fir<=w){
            ans +=arr[i].sec;
            w -= arr[i].fir;
            selected[i]=arr[i].fir;
        }

        else{
        int rem= w-arr[i].fir;
        ans += (arr[i].sec/arr[i].fir)* rem;
        w=0;
        selected[i]=arr[i].fir;
        break;
        }
        
   }

   rep(i,0,selected.size()){
       cout<<selected[i];
   }
    cout << ans;
    return 0;
}
