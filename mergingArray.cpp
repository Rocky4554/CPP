#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> nums1,int m,vector<int> nums2,int n){
    int len=m+n-1;
    m=m-1;n=n-1;
    while(m>=0 && n>=0){
        if(nums1[m]<=nums2[n]){
            nums1[len]=nums1[m];
            m--;len--;
        }
        else{
            nums1[len]=nums2[n];
            n--;len--;
        }
    }

    if(m<0){
        while(n>=0){
            nums1[len--]=nums2[n--];
        }
    }
    else{
        while(m>=0){
            nums1[len--]=nums1[m--];
        }
    }
    return nums1;

    }


int main(){

    vector<int> num1={1,2,2,0,0,0};
    int x=num1.size();
    vector<int> num2={2,3,6};
    int z=num2.size();

    vector<int> fc;
    fc=merge(num1,x,num2,z);

    for(int i=0;i<fc.size();i++)
    cout<<fc[i]<<" ";
    

    return 0;
}