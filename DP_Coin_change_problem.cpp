#include<bits/stdc++.h>
using namespace std;

int total(int n,int coins[],int tm){
    if(tm<0){
        return 0;
    }
    if(n<=0 && tm>=1){
        return 0;
    }
    if(tm==0){
        return 1;
    }
    else{
        return total(n-1,coins,tm)+ total(n,coins,tm-coins[n-1]);
    }
    

}

int main(){
    int n;
    cout<<"Enter the size\n";
    cin>> n;

    int coins[n];
    cout<<"Enter the coins\n";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int tm;
    cout<<"Enter the total amount\n";
    cin>>tm;

    cout<<total(n,coins,tm);
    return 0;
}