#include<bits/stdc++.h>
using namespace std;

int power(int r,int N){// here we are finding the power
    if(N==0){
        return 1;
    }

    int temp=power(r,N/2);
                 
    if(N/2==0){
        return pow(temp,2);
    }
    else{
        return (r*pow(temp,2));
    }
}

solve(int a,int r,int N){
    int An=a*power(r,N-1);
    return An;
}



int main(){

    int a,r,N;
    cin>>a>>r>>N;

    cout<<"Nth term is:";
    cout<<solve(a,r,N);

    return 0;
}

