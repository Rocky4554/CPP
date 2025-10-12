#include<bits/stdc++.h>
using namespace std;

int main(){

cout<<"siz of array\n";
int n;
cin>>n;
cout<<"Enter the value of k\n";
int k;
cin>>k;

map<int,int> mr[k];
for(int i=0;i<n;i++){//inserting fequency of element in our map of array 1 2 3 4 5 6 7 8 9 10
       int num;cin>>num;                                  //indexing[i%k]0 1 2 0 1 2 0 1 2 0 [key]
    mr[i%k][num]++;                         //fequency                   1 1 1 1 1 1 1 1 1 1 [key]

}
int ans=0;
for(int i=0;i<k;i++){
    int total=0; int maximum = -1;
    for(auto [num,cnt]:mr[i]){
        total = total + cnt;
        maximum= max(maximum,cnt);
    }

    ans = ans +(total-maximum);

}

cout<<ans<<endl;


    return 0;
}