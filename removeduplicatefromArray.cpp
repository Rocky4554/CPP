#include<bits/stdc++.h>
using namespace std;



int main(){

int n;
cout<<"Enetr the size\n";
cin>>n;

int ar[n];
cout<<"Enter the values in array\n";
for(int i=0;i<n;i++){
cin>>ar[i];
}

int sr[n];
int j=0,i;

for( i=0;i<n;i++){
if(ar[i]!=ar[i+1]){
    sr[j++]=ar[i];
}
}
sr[j++]=ar[i];

cout<<"Resulted array\n";
for(int i=0;i<n-1;i++){
cout<<sr[i]<<" ";
}
  return 0;
}