#include<bits/stdc++.h>
using namespace std;

void reverse(string &s,int n,int i){
    if(i>n/2){
        return;
    }
     swap(s[i],s[n-i-1]);
    reverse(s,n,i+1);
}

int main(){

    string s="Raunak";
    int n=s.size();

    reverse(s,n,0);
    cout<<s;//print the string after reversing.
     return 0;
}