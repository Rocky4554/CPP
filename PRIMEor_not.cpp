#include<bits/stdc++.h>
using namespace std;
int  main(){

int n;
cin >> n;
int flag=0;

for(int i=2;i<=n/2;i++){
    if(n%i==0){
        flag=1;
        break;
    }
}

if (n==1){
    cout<<"not prime\n";
}else{
    if(flag==0){
        cout<<"It is a prime no.\n";
    }else{
        cout<<"It is not a prime no.\n";
    }

}
return 0;
}