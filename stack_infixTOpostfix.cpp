#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){// same for prefix .
    
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
string conversion(string infix){// for prefix reverse the input string.
string postfix;
stack<char> st;
 for(int i=0;i<infix.length();i++){
        if((infix[i]>='a'&& infix[i]<='z')|| (infix[i]>='A'&& infix[i]<='Z')){
            postfix +=infix[i];
        }
        else if(infix[i]=='('){//reverse the bracket for prefix.
          st.push(infix[i]);
        }
        else if(infix[i]==')')//reverse the bracket fot prefix.
        {
            while(!st.empty() && st.top()!='('){// reverse the bracket for prefix.
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
    return postfix;//at last reverse the resultant output and return it(for prefix).
}


int main(){
    string ch="(a*b)+c";
    cout<<conversion(ch);
    
    return 0;
}
