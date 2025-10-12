#include<bits/stdc++.h>
using namespace std;

 bool progrssion(int sr[],int n){
    for(int i=0;i<n-1;i++){
         int j=i-1;int k=i+1;

        while(i>=0&&j<n-1){
         if(sr[j]+sr[k]==2+sr[i]){
             return true;
         
             (sr[j]+sr[k]>2+sr[i]?i--:k++)

             }
        }
    }
    return false;
}
int main(){
    int n =4;
    int sr[n]={2,4,6,7};

    cout<<progression(sr[],n)

    return 0;
}