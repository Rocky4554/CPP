#include<bits/stdc++.h>
using namespace std;

bool campare(pair<int,int> p1 ,pair<int,int> p2){
    return p1.first<p2.first;
}

int main(){

    int ar[]={4,2,1,-1,7,8,0};
    int n =sizeof(ar)/sizeof(ar[0]);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
    v.push_back(make_pair(ar[i],i));//making vector of pairs.
    }

    sort(v.begin(),v.end(),campare);//important.(sorting array with its index no.)
    for(int i=0;i<n;i++){//imp
        ar[v[i].second ]=i;//imp.
    }

    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}