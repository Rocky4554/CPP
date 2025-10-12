#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
   while(t--){
    int D,d;
    cin>> D >> d;int A=10,B=21,C=42;
        int x=D*d;
        if(x<A || x>C){
            cout<<0;
        }
        else if( x==A || x==B || x==C){
            cout<<1;
        }
        else{
            cout<<2;
        }
        
        
   }
    
	// your code goes here
	return 0;
    
}