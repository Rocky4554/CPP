#include<bits/stdc++.h>
using namespace std;

int coinChange(int n,int coins[],int tm){
    if (tm==0){// here in minium coins required if total amount is equal to zero then coins required is also zero
        return 1;
    }
    int res=INT_MAX;
    for(int i=0;i<n;i++){// traversing the coin array
    if(coins[i]<=tm){//
        int sub_res= coinChange(n,coins,tm-coins[i]);//

        if(sub_res!=INT_MAX && sub_res +1 < res)
        res= sub_res+1;storing the result.
    }
    }

    return res;
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

    cout<<coinChange(n,coins,tm);

    return 0;

    return 0;
}