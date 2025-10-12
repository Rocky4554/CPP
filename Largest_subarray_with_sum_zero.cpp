#include<bits/stdc++.h>
using namespace std;

int largest(int A[]){

    unordered_map<int,int> m;
    int maxi=0;int sum=0;
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++){
        sum +=A[i];
        if(sum==0){
         maxi=i+1;//if sum is zero then we know that previous subarray is not included.
        }
        else 
        {
            if(m.find(sum)!=m.end()){
                maxi=max(maxi,i-m[sum]);//i-value in table table of key m[sum].
            }

        
            else{
            m[sum]=i;//sum is key and i is the value.
            }
        }
    }
    return maxi;

}

int main(){

    int n;
    cout<<"Enter the size of array\n";
    cin>>n;

    int A[n];
    cout<<"Enetr the array\n";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    cout<<largest(A);

    return 0;

}