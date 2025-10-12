#include<bits/stdc++.h>
using namespace std;
// different from rain water trapping
//in rainwater trapping there was no gap between buildings
//all building were touching each other. 
maxwater(int height[],int n){
    
    int i=0;int j=n-1;int Max=0;

    while(j>i){
         int area = min(height[i],height[j])*(j-i);
         Max=max(area,Max);
         if(height[i]<=height[j]){
            i++;
         }
         else{
            j--;
         }
    }
    return Max; 
}
int main(){
    cout<<"Enter the size\n";
    int n;
    cin>>n;
    int ar[n];
    cout<<"Enter the heights";
    for(int i=0; i<n; i++){
        cin>>ar[i];

        cout<<maxwater(ar,n)<<endl;
    }
     return 0;
 }