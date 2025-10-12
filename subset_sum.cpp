#include<bits/stdc++.h>
using namespace std;

bool check(int ar[],int n,int sum){

bool s[n+1][sum+1];
    for(int i =0;i<n+1;i++)//if sum is zero for all n then empty set is possible
        s[i][0]=true;
        for(int i=0;i<sum+1;i++)//if ther is no number then no set is possible for sum
            s[0][i]=false;
    //printing the s[][] foer subset sum.
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(ar[i-1]>sum){
                s[i][j]=s[i-1][j];

            }
           else{
                s[i][j]=s[i-1][j-ar[i-1]] || s[i-1][j]; 
        }
    }

    }
    return s[n][sum];

}

int main(){
     cout<<"enter the sum"<<endl;
    int sum;
    cin>>sum;
    
    cout<<"enter the size"<<endl;
    int n;
    cin>>n;
    
    int ar[n];
    cout<<"enter the array values"<<endl;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    if(check(ar,n,sum)==true)
    cout<<"subset present"<<endl;
    else
    cout<<"subset not present"<<endl;

    return 0;
}