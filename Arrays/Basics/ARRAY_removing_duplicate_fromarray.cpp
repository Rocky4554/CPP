#include<bits/stdc++.h>
using namespace std;

vector<int> duplicate(int ar[],int n){
    unordered_map<int,int> m;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(m[ar[i]]==0){
            v.push_back(ar[i]);
        }
        m[ar[i]]++;
    }

    return v;
}


int main(){

    int n;
    cin>>n;
    
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    vector<int> ans = duplicate(ar,n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}