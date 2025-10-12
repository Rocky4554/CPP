#include<bits/stdc++.h>
using namespace std;

int evaluate(string infix){
    stack<char> st;
    for(int i=infix.length()-1;i>=0;i--){// reverse the loop for postfix. 
        if(infix[i]>='0' && infix[i]<='9'){
            st.push(infix[i]-'0');// here we are subtracting ASCII value of zero with our char at ith position.
            //It changes it to integer value.
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(infix[i]){
                case '+':
                st.push(op1 + op2);
                break;

                case '-':
                st.push(op1 - op2);
                break;
                
                case '*':
                st.push(op1*op2);
                break;

                case '/':
                st.push(op1/op2);
                break;

                case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
}

int main(){

    string infix="-+7*45+20";
    cout<<evaluate(infix);

    return 0;
}