#include<bits/stdc++.h>
using namespace std;
   
int smallest(int ar[],int n,int k){
    priority_queue<int> max;//create maxheap.
    for ( int i = 0; i < n; i++)
    {
        max.push(ar[i]);

        if(max.size()>k){
            max.pop();
        }
    }
    return max.top();
}

int main()
{
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
    cout<<smallest(ar,n,k);
    
    return 0;
}