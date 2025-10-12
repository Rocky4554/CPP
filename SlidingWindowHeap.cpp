#include<bits/stdc++.h>
using namespace std;

void max(queue<int> q){
    int max=0;
    
    while(!q.empty()){
        if(max<q.front())
        max=q.front();
        q.pop();
    }
    cout<<max<<endl;
} 

void maximum(int *ar,int n,int k){
    queue<int> q;
    if(n<k)
    cout<<"invalid\n";

    for(int i=0;i<n;i++){
        if(i<k){// for first window
        q.push(ar[i]);
        }
        
        else{//for middle window
            max(q);
            q.pop();
            q.push(ar[i]);
           
        }

    }//for last window.
    max(q);
    return;
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
maximum(ar,n,k);

    return 0;
}