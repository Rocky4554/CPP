#include<bits/stdc++.h>
using namespace std;

bool balance(string s){
    int n =s.length();
    stack<char> st;
    bool res=true;
    for(int i=0;i<n;i++){
        if(s[i]=='('||s[i]=='{'|| s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();;p
            }
            else{
                res=false;
                break;
            }
        }
            else if(s[i]=='}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                res=false;
                break;
            }
            }
            else if(s[i]==']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                res=false;
                break;
            }
            }
            else{
                res=false;
                return res;
            }
        }
    
    if(!st.empty()){
        res=false;
        return res;
    }
    return res;

}

int main(){
    string s ="(({[)";
    if(balance){
        cout<<"braces are balanced\n";
    }
    else{
        cout<<"\n braces are not balanced";
    }
    return 0;
}
