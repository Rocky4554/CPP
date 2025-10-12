#include<bits/stdc++.h>
using namespace std;

int power(int r,int N){// here we are finding the power
    int pow=1;
    for(int i=1;i<N;i++){
        pow=pow*r;
    }
    return pow;
}

solve(int a,int r,int N){
    int An=a*power(r,N);
    return An;
}



int main(){

    int a,r,N;
    cin>>a>>r>>N;

    cout<<"Nth term is:";
    cout<<solve(a,r,N);

    return 0;
}