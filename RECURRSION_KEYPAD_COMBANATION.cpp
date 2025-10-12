#include <bits/stdc++.h>
using namespace std;

void solve(string str,vector<string>& ans,string p,int index)
{
    if(str.size()==0){
        ans.push_back(p);
        return ans;
    }
    int digit= str[0]-'0';
    for(int i=(digit-1)*3;i<digit*3;i++){
        char c=(char)('a' + i);
        // ans.push_back(c);   
        p=p+c;
        solve(str.substr(index),ans,p,index+1);

    }
}

int main()
{
    string str;
    getline(cin, str);
    string p;
    // vector<vector<string>> res;
    vector<string> ans;
    int index=0;

    vector<string> res=solve(str,ans,p,index);
    for(auto it:res){
        cout<<it<<" ";
    }
}