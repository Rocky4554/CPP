#include<bits/stdc++.h>
using namespace std;
void solve(itn ar,int n){
    int j=0;int temp=0;
for(int i=1;i<n;i++){
if(ar[i]<ar[i-1]){
    temp=ar[i-1];
    ar[i-1]=ar[i];
    ar[i]=temp;
}
 }

}

int  main(){

int ar=[];
int n =sizeof(ar)/sizeof(ar[0]);

solve(ar,n);

return 0;
}