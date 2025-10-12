#include<bits/stdc++.h>
using namespace std;

int prime(int n){
    int c=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            c=0;
            break;
        }
        if(c==1){
            return 1;
        }

    }
    return 0;
}

int main(){
    vector<int> ar;int sum=0;
    int a,b,i,j,flag;

    cin >> b;

    cout<<"prime no between given range are\n";

    for(i=2;i<=b;i++){

        if(i==1 || i==0){
            continue;
        }
        flag=1;
        for(j=2;j<=i/2;j++){
            if(i%j==0){
                flag=0;
                break;
            }  
        }
        if(flag==1){ 
        ar.push_back(i);
        }

    }  

    for(int i=0;i<ar.size();i++){
        sum += ar[i];
        int cnt =prime(sum);
        if(cnt==1){
            cout<<sum<<" ";  
        }

    } 

    return 0;
}