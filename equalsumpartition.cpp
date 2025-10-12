#include<bits/stdc++.h>
using namespace std;
//we have to find two such subset that sum of both subset is equal
bool equal(int ar[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum +=ar[i];
     
     
     if(sum%2 !=0){
         return false;
        }
        
            
bool s[n+1][sum/2+1];
    for(int i =0;i<n+1;i++)//if sum is zero for all n then empty set is possible
        s[i][0]=true;
        for(int i=0;i<sum/2+1;i++)//if ther is no number then no set is possible for sum
            s[0][i]=false;
    //printing the s[][] foer subset sum.
    for(int i=1;i<n+1;i++){
        for(int j=1;j<(sum/2)+1;j++){
            if(ar[i-1]>sum/2){
                s[i][j]=s[i-1][j];

            }
           else{
                s[i][j]=s[i-1][j-ar[i-1]] || s[i-1][j]; 
        }
            
        }
}

    return s[n][sum/2];

}

int main() 
{
    cout<<"enter the size of array"<<endl;
    int n;
    cin>>n;

    int ar[n];
    cout<<"enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    if(equal(ar,n)==true)
    cout<<"present"<<endl;
    else 
    cout<<"not present";

     return 0;
}