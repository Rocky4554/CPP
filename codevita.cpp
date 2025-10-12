#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
int flag=0;

for(int i=2;i<=n/2;i++){
    if(n%i==0){
        flag=1;
        break;
    }
}

if (n==1){
    return false;
}else{
    if(flag==0){
        return true;
    }else{
        return false;
    }

}
 
}

int find(int n,int ans){

for(int i=1;i<=n;i++){
 if(isprime(i)){
     n--;
 }

}
if(n==1){
    return ans;
}else{
    ans++;
    cout<<n<<endl;
    return find(n,ans);

}

}

int main(){

    int n;
    cout<<"Enter the no of emails\n";

    cin>>n;
    int ans=0;

    cout<<find(n,ans)<<endl;

    return 0;
}