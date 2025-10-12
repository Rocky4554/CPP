#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    string s,p="hello";
    int j=0,total=0;

    cin>>s;

    for(int i=0;i<s.length();i++){
        if(s[i]==p[j]){
            j++;
            total++;
        }
        if(total==p.size()){
            break;
        }
    }

    if(total==p.size()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO";
    }



    return 0;
}