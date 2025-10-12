#include<bits/stdc++.h>
using namespace std;

int subsequence(string X,string Y,int n,int m){
    if(n==0||m==0){
        return 0;

    }
    if(X.at(n-1)==Y.at(m-1)){
        return 1+subsequence(X,Y,n-1,m-1);
    }
    else{
        return max(subsequence(X,Y,n-1,m),subsequence(X,Y,n,m-1));
    }
}

int main(){
    string X;
    cout<<"enter the first strings"<<endl;
    getline(cin,X);
    string Y;
    cout<<"enter the second strings"<<endl;
    getline(cin,Y);
    int n =X.size();
    int m =Y.size();

    cout<<"longest"<<endl;
    cout<<subsequence(X,Y,n,m);
     
     
    return 0;
}
