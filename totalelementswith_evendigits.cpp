#include<bits/stdc++.h>
using namespace std;

int even(int ar[]){
int total=0;
for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
    int count=0;
    while(ar[i]=0){
        ar[i]=ar[i]/10;
        count++;
    }
    if(count%2==0){
        total++;
    }
}
return total;
}
int main(){
    int n;
    cout<<"Enter the size\n";
    cin>>n;
    int ar[n];
    cout<<"Enter the array\n";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cout<<"answer\n";
    cout<<even(ar);

    return 0;
}