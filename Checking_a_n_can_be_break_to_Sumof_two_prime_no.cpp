#include<bits/stdc++.h>
using namespace std;

class Prime{
    public:

    bool isPrime(int n){
        if(n<=1){
            return 0;// 1 is not a prime no;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return 0;
            }

        }    
        return 1;
    }

    bool check(int n){
        for(int i=1;i<n;i++){// subtracting the no from 1 to n-1;
            int d=i,d1=n-i;// not taking globally 
        if(isPrime(d) && isPrime(d1)){
            return 1;
        }
        }
        return 0;
    }


};

int main(){
cout<<"Enter the no: \n";
int n;
cin>>n;

Prime ob;
if(ob.check(n)){
    cout<<"true"<<endl;
} else{
    cout<<"False"<<endl;
}

return 0;

}