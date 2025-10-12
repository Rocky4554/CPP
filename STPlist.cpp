#include<bits/stdc++.h>
using namespace std;

int main(){

    list<int> ar;
    ar.push_back(1);
    ar.push_back(2);
    ar.push_back(3);
    ar.push_back(4);

    for(auto it:ar){
        cout<< it  <<endl;
    }
    cout<<ar.front();

     return 0;

}