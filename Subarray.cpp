#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    int n =s.size();

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<s[k]<<"";
            }
         cout<<'\n';
        }
    }
    return 0;
}