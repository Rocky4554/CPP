#include<bits/stdc++.h>
using namespace std;

int maximum(int wt[],int v[],int n,int cap){
        int i,j;
        int k[n+1][cap+1];

        for(int i=0;i<n+1;i++){
        for(int j=0;j<cap+1;j++){
                if(i==0||j==0){
                 k[i][j]=0;
                }

                 else if(wt[i-1]>j){
                    k[i][j]=k[i-1][j]; 
                }
                else{
                    k[i][j]=max(v[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
                }
            }
        }
        return k[n][cap];
}
            
int main(){
    cout<<"Enter thr size"<<endl;
    int n;
    cin>>n;
    
    cout<<"Enter thr capacity"<<endl;
    int cap;
    cin>>cap;

    int wt[n];
    cout<<"Enter the weights"<<endl;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int v[n];
    cout<<"Enter the values"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Maxium profit"<<endl;
    cout<<maximum(wt,v,n,cap);
    return 0;
}