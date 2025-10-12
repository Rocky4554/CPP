#include<bits/stdc++.h>
using namespace std;

int second(int ar[],int n,int target){
    int last=-1,sl=-1;
    for(int i=0;i<n;i++){
        if(ar[i]==target && last!=-1){
            sl=last;
            last=i;
        }

        else if(ar[i]==target && last ==-1){
            last =i;
        }
    }
    return last;
}

int main(){

    int n;
    cin>>n;

    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    int target;
    cin>>target;

    cout<<second(ar,n,target);


    return 0;
}