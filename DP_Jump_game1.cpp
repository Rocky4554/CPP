#include<bits/stdc++.h>
using namespace std;

bool find(int ar[],int n){
    int last =n-1;
    for(int i=n-2;i>=0;i--){
        if(i+ar[i] >= last){
            last =i;
        }
    }

    return last==0;
}

int main(){
  
    int ar[]= {2,2,1,1,4};
    int n =sizeof(ar)/sizeof(ar[0]);
    
    if(find(ar,n)){
        cout<<"possible to reach end of a array"<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }

    return 0;
}