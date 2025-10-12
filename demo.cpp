#include<bits/stdc++.h>
using namespace std;

bool isAlphabet(char c){
 return ((c>='a'&& c<='z' || c>='A' && c<='Z'));
}

string reverse(string str){
    int e=str.size() - 1 , l=0;
    char temp;
    while(l<e){
        if(!isAlphabet(str[l])){l++;
        }
        else if(!isAlphabet(str[e])){
            e--;
        }
        else{
            temp=str[l];
            str[l]=str[e];
            str[e]=temp;
            l++;
            e--;
        }
    }
    return str;
}

int main(){
    string str;
    cin>>str;
    cout<<"original--"<<str<<endl;
    cout<<reverse(str);
    return 0;
}