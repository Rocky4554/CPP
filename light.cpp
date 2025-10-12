#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    string t;
    cin>>t;

    int result =0;

    int p,q;
    for(int i=0;i<s.size();i++){

        p=s[i]-'0';
        q=t[i]-'0';
         
        result = result + abs(p-q);
    }

    if(result>0){
        cout << result;
    }
    else{
        cout << -1;
    }

    return 0;

}