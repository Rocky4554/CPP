#include<bits/stdc++.h>
using namespace std;

int sqrt(int x){
long int l=0,h=x,m;
        if(x==1)
          return 1;
        long int ans=0;
        while(l<h)
        {
           m=(l+h)/2;
           cout<<"mid "<<m<<endl;
           if(m*m==x)
           {
             ans=m;
             break;
           } 
           else if(m*m>x)
              h=m;
           else
           {
               ans=m;
               l=m+1;
           }
        }
        
     return ans;
}

int main(){
    int x;
    cin>>x;
    cout<<"ans"<<endl;
    cout<<sqrt(x);
    return 0;
}