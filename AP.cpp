#include<bits/stdc++.h>
using namespace std;

int progression(int sr[],int n){
    for(int i=1;i<n-1;i++){
         int j=i-1;int k=i+1;

        while(i>=0 && j<=n-1){
         if(sr[k]+sr[j]==2*sr[i])
             return 1;
         
             (sr[k]+sr[j]<2*sr[i])?k++:j--;

             
        }
    }
    return 0;
}
int main(){
    
    int  sr[]={2,4,6};
    int n =sizeof(sr)/sizeof(sr[0]);

    cout<<progression(sr,n);

    return 0;
}