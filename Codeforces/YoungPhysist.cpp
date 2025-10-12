#include<iostream>
using namespace std;

int main(){

int n;
cin>>n;long long x,y,z;long long sum=0,sum1=0,sum2=0;
while(n--){
cin>>x>>y>>z;
sum +=x;
sum1 +=y;
sum2 +=z;
}
// cout<<result;
if (sum==0 && sum1==0 && sum2==0){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}

return 0;

}

