#include<bits/stdc++.h>
using namespace std;

vector<int> smallest(int ar[],int n)
{
vector<int> v;
stack<int> st;
for(int i=0; i<n; i++){
    if(st.size()==0)
    v.push_back(-1);

else if(st.top()<ar[i] && st.size >0){
    v.push_back(st.top());
    }
    else if(st.top()>=ar[i] && st.size() >0){        
        while(st.top()>=ar[i] && st.size() >0){
            st.pop();
        }
        if(st.size()==0)
        v.push_back(-1);
        else
        v.push_back(st.top());
    }
    st.push(ar[i]);
}
return v;

}

int main(){
    int ar[] ={1,3,2,4};
    int n = 4;

    cout<<"ans array\n";
    cout<<smallest(ar,n);
    return 0;
}