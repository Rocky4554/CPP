#include<bits/stdc++.h>
using namespace std;

int nosubarray(int nums[],int k){
    map<int, int> m; 
    int count=0;
    int xorr=nums[0];
    for(int i=1;i<sizeof(nums)/sizeof(nums[0]);i++){
        xorr = xorr ^ nums[i];
  
        if(xorr==k){
            count++;

        }
        if(m.find(xorr ^ k)!=m.end())

        
            count += m[xorr ^k];
        

            m[xorr]++;
       
    }
    return count;

}

int main(){

    int n;
    cout<<"Enter the size\n";
    cin>>n;
    int nums[n];
    cout<<"Enter the array\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<<"Enter the XOR \n";
    cin>>k;

    cout<<"Total no of subarray\n";
    cout<<nosubarray(nums,k);

    return 0;
}