#include<bits/stdc++.h>
using namespace std;
// this is a program of segmente sieve (means finding prime in a given range)
const int N =1000000;
bool sieve[N +1];
void createSieve(){

 for(int i=2;i<=N;i++){
     sieve[i]=true;
 }

 for(int i=2;i*i<=N;i++){
     if(sieve[i]==true){  
         for(int j=i*i;j<=N;j +=i){
             sieve[j]=false;  
             
     }
}
}

vector<int> getprime(int N){
    vector<int> ar;
    for(int i=2;i<=N;i++){
        if(sieve[i]==true){
            ar.push_back(i);
        }
    }
    return ar;
}



int main(){

    createSieve();

    int l,r;
    cin>> l >> r;

 // storing all our prime
    vector<int> allprime = getprime(sqrt(r));


    // create a range array of size r-l+1 and mark it true
    int range[r-l+1];
    for(int i=0;i<r-l+1;i++){
        range[i]=1;
    }
// now we have to mark all multiple of our prime no stored in all prime to false

// here we are finding the first multiple 
    for(auto it: allprime){
        int firstmul=(l/it)*it;// formula for first mulltiple
        if(firstmul<l){//if our multiple is less  than l then we will add our prime to it 
            firstmul += it;
        }
        // here we are marking the multiple to false
        for(int j=max(firstmul,it*it);j<=r;j=j+it){
            range[j-l]=0;// here we are calculating the index of our range array on where the multiple will be lying 
        }

    }

    // getting all our prime till r
    for(int i=l;i<=r;i++){
        if(range[i-l]==1){
            cout<< i <<" ";
        }

    }

    return 0;
}
// Our range array
// l=2 r=25  so r-l=1 wil be 24
// [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23]--> index
// [2 3 4 5 6 7 8 .......]-->range array stored on thar index
