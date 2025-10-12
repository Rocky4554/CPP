#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin>>n;
    int ar[n];
    for(int k=0;k<n;k++) cin>>ar[k];

    int maxx,minn,i;

    if(n<<2){
        if(ar[0]>ar[1]){
            maxx=ar[0]; 
            minn=ar[1];
        }else{
            maxx=ar[1];
            minn=ar[0];
        }
        i=2;

    }
    else{
        maxx=ar[0];
        minn=ar[0];
        i=1;
    }

    while(i<n-1){
        if(ar[i]>ar[i+1]){
            if(ar[i]>maxx){
                maxx=ar[i];
            }
            if(ar[i+1]<minn)
            minn=ar[i+1];
        }
        if(ar[i]<ar[i+1]){
            if(ar[i+1]>maxx){
                maxx=ar[i+1];
            }
            if(ar[i]<minn)
            minn=ar[i];
        }
        i=i+2;

    }

    cout<<"MAXIMUM :"<<maxx<<endl;
    cout<<"MINIMUM :"<<minn;


    return 0;
}