#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int v[],int n,int cap){
    if(n ==0 || cap ==0 ){// if there is no items and capacity of knapsack is also zero.
        return 0;
    }

    else if(wt[n-1] > cap){
        return knapsack(wt,v,n-1,cap);
    }

    else{
        return max(v[n-1] + knapsack(wt,v,n-1,cap-wt[n-1]),knapsack(wt,v,n-1,cap));
    }
}

                  
int main(){
    cout<<"Enter the size"<<endl;
    int n;
    cin>>n;
    
    cout<<"Enter the capacity"<<endl;
    int cap;
    cin>>cap;

    int wt[n];
    cout<<"Enter the weights"<<endl;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int v[n];
    cout<<"Enter the values"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Maximum profit"<<endl;
    cout<<knapsack(wt,v,n,cap);

    return 0;
}
