#include<bits/stdc++.h>
using namespace std;

void print(stack<int> &st){
     while(!st.empty()){
        int res=st.top();
        st.pop();
        cout<< res <<" ";

    }
    
}

void insert(stack<int> &st,int temp){
        if(st.empty()){
             st.push(temp);
             return;
        }

        int rep=st.top();
        st.pop();
        insert(st,temp);
        st.push(rep);
        return;
    }


 void reverse(stack<int> &st){
     if(st.empty()==1){
         return;//not returning anything because the stack is itself is reversed as it is containing a single element
     }

     int temp=st.top();
     st.pop();
     reverse(st);
     insert(st,temp);
    return; 
    }

    
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

     cout<<"Original stack"<<endl;
    cout<< 5 <<" "<< 4 <<" "<< 3 <<" "<< 2 <<" "<< 1 <<  endl;

    reverse(st); 
    
    cout<<"Reversed stack"<<endl;
    
    while(!st.empty()){
        int res=st.top();
        st.pop();
        cout<< res <<" ";
    }

    return 0;
}