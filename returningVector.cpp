#include<bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> v){
    vector<int> s;

    for(int i=0;i<v.size();i++){
        s.push_back(v[i]*2);
    }
    return s;
}

int main(){
    vector<int> vr{1,2,3,4,5}; 
    // vr.push_back(1); 
    // vr.push_back(2); 
    // vr.push_back(3); 
    // vr.push_back(4); 
    vector<int> fc;
    fc=fun(vr);// function call.

    for(int i=0;i<fc.size();i++){
        cout<<fc[i]<<" ";
    }

    return 0;
}