#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    int i=0,j=s.size()-1;

    while(i<=j){
        if(s[i++]!=s[j--]){
            return false;
        }
    }
    return true;
}

bool palindrome(string s){
    string s1,s2,s3;
    s1=s[0];
    for(int i=1;i<s.size();i++){
        s2=s.substr(1,i);
        s3=s.substr(i+1);
    }
    
    if(check(s1) && check(s2) && check(s3)){
        return true;
    }

    return false;

}

int main(){
    string s;
    cin>>s;

    cout<<palindrome(s);
    return 0;
}