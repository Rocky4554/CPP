#include<bits/stdc++.h>
using namespace std;

int sum(queue<int> q){
    int sum=0;
    while(!q.empty()){
        sum += q.front();
        q.pop();
    }
    return sum;
} 

int maximum(int *ar,int n,int k){
    queue<int> q;
    vector<int> v;
    for(int i=0;i<n;i++){
        if (i<k){
        // if(q.empty() && q.size()<=k){
          q.push(ar[i]);
        }
        else{
        sum(q);
        v.push_back(sum(q));
        q.pop();
        q.push(ar[i]);
        }
    }
    sum(q);
    v.push_back(sum(q));
    
    int max=0;
    for(int i=0;i<v.size();i++){
        if(max<ar[i])
        max=ar[i];
    }
  return max;
}

int main(){

cout<<"Enter the size\n";
int n;
cin>>n;

int ar[n];
cout<<"Enter the vaues in array\n";
for (int i = 0; i <n ;i++)
{
    cin>>ar[i];
}

cout<<"Enter the values of k\n";
int k;
cin>>k;

cout<<"maximum of all subarray of size  k\n";
cout<<maximum(ar,n,k);

    return 0;
}