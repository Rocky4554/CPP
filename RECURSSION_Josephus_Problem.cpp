#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k){
    if(n==1){
        return 0;
    }

    int x=solve(n-1,k);
    int y=(x+k)%n;
    return y;
}

int main(){
    int n;
    cout<<"Enter the no of peoples \n";
    cin>>n;

    int k;
    cout<<"Enter the position to get killed\n";
    cin>>k;

    cout<<"Position of the person remaining at last\n";
    cout<<solve(n,k)<<endl;

    return 0;
}
