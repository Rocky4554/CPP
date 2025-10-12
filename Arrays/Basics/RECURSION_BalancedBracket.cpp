#include<bits/stdc++.h>
using namespace std;

void solve(vector<string> &v,string &str,int open,int close){
    if(open==0 && close==0){// both open and close are empty
        v.push_back(str);
        return;
    }

    if(open!=0){// if open bracket is not empty
         string str1=str;
        str1.push_back('(');
        solve(v,str1,open -1,close);
    }
    if(close>open){//do not use equal to open
         string str2=str;
        str2.push_back(')');
        solve(v,str2,open,close-1);
    }
}

vector<string> balanced(int n){
    vector<string> v;
    string str="";
    solve(v,str,n,n);
    return v;

}

int main(){
    int n;
    cout<<"Enter the no the of braces\n";
    cin>>n;

    vector<string> out;
    out=balanced(n);
 
    for(int i=0;i<out.size();i++){
        cout<<out[i]<<" ";
    }
    return 0;
}