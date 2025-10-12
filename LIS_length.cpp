#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[]={4,5,1,3};
    int n =sizeof(ar)/sizeof(ar[0]);
    vector<int> d(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(ar[i]>ar[j]){
                d[i]=max(d[i],d[j]+1);
            }
           
        }
    }

    int len=0;
    for(int i=0;i<n;i++){
        len=max(len,d[i]);
    }

    cout<<"len :"<<len;

return 0;
}