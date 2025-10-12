#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    
        if(ch=='^'){
            return 3;
        }
        else if(ch=='*'|| ch=='/'){
            return 2;
        }
        else if(ch=='+'|| ch=='-'){
            return 1;
        }
        else{
            return -1;
        }

}
string conversion(string infix){
reverse(infix.begin(),infix.end());
string postfix;
stack<char> st;
 for(int i=0;i<infix.length();i++){
        if((infix[i]>='a'&& infix[i]<='z')|| (infix[i]>='A'&& infix[i]<='Z')){
            postfix +=infix[i];
        }
        else if(infix[i]==')'){
          st.push(infix[i]);
        }
        else if(infix[i]=='(')
        {
            while(!st.empty() && st.top()!=')'){
            postfix +=st.top();
            st.pop();

            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && (precedence(st.top())>precedence(infix[i]))){
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
            
        }
 }
     while(!st.empty()){
            postfix +=st.top();
            st.pop();
            
        }
        reverse(infix.begin(),infix.end());
    return postfix;
}


int main(){
    string ch="(a*b)+c";
    cout<<conversion(ch);
    
    return 0;
}
