#include<bits/stdc++.h>
using namespace std;

int main(){
    string X,Y;
    cout<<"enter the two strings";
    getline(cin,X);
    getline(cin,Y);
    int m =X.length();
    int n =Y.length();
     
     int t[m+1][n+1];
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(i==0||j==0){
                  t[m][n]=0;
              }
          }
     }
           for(int i=1;i<n;i++){
                for(int j=1;i<n;j++){
                    if(X.at(i-1)==Y.at(j-1)){
                        t[m][n]=1+t[i-1][j-1];

                    }
                    else{
                        t[m][n]=max(t[i][j-1],t[i-1][j]);
                    }
                }
           }
 cout<<t[m][n];
    return 0;
}
