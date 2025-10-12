#include<bits/stdc++.h>
using namespace std;


int minsubset(int ar[],int n){
    int range=0;
    for(int i=0; i<n; i++)
     range +=ar[i];

    bool s[n+1][range+1];
    for(int i =0;i<n+1;i++)//if range is zero for all n then empty set is possible
        s[i][0]=true;
        for(int i=0;i<range+1;i++)//if ther is no number then no set is possible for range
            s[0][i]=false;
    //printing the s[][] foer subset range.
    for(int i=1;i<n+1;i++){
        for(int j=1;j<range+1;j++){
            if(ar[i-1]>range){
                s[i][j]=s[i-1][j]; 

            }
           else{
                s[i][j]=s[i-1][j-ar[i-1]] || s[i-1][j]; 
           }
       }
    }
    // vector<int> v;
    // for(int j=0; j<range/2; j++){
    //     if(s[n][j]== true);
    //     v.push_back(j);
    // }
    // int Min=INT_MAX;
    // for(int i=0; i<v.size(); i++){
    //     Min=min(Min,range-2*v[i]);
    // }
    // return Min;
    int Min=INT_MAX;
    for(int j=range/2;j>=0;j--){
        if(s[n][j]==true);
        Min = range-2*j;
        break;
    }
    return Min;


}
int main(){

    int ar[]={3,1,4,2,2,1};
    int n = sizeof(ar)/sizeof(ar[0]);
    // int range=0;
    // for(int i=0; i<n;i++){
    //     range +=ar[i];
    
    cout<<"min subset\n";
    cout<<minsubset(ar,n);
    
     return 0;
}