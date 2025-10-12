#include<bits/stdc++.h>
using namespace std;
int maxi=INT_MIN;

int maximum(int ar[],int n){
    for(int i=0;i<n;i++){
        if(ar[i]>maxi){
            maxi=ar[i];
        }

    }
    return maxi;
}

int main(){
    int n ;
    cin>>n;

    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    int k;
    cin>>k;

    int sum=0;
    for(int i=0;i<n;i++){
        sum +=ar[i];
    }

    while(k>0){
        int m=maximum(ar,n);
        sum = sum-m;
        int c=ceil(m/2);
        
        for(int i=0;i<n;i++){
            if(ar[i]==m){
                ar[i]=c;
            }
        }
        sum = sum +c;
        cout<<sum<<endl;
        --k;
    }       
    
    cout<<"minimum sum : "<<sum<<endl;
    
    return 0;
}