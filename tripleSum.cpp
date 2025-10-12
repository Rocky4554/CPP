#include<bits/stdc++.h>
using namespace std;

void triplet(int *ar,int n,int target){
  int l,h;
    int k=3;//it is 3 because question is triplet sum,4 if question was four sum.
    sort(ar,ar+n);
    for(int i=0;i<n-k+1;i++){//setting first pointer of triplet as ar[i]
    l=i+1;//setting second pointer of triplet.
    h=n-1;//setting third pointer of triplet;

    while(l<h){
        if(ar[i]+ar[l]+ar[h] == target){
            cout<<ar[i] <<ar[l] <<ar[h] <<endl;
            break;
        }
        else if(ar[i]+ar[l]+ar[h] < target){
            l++;
        }
        else{
            h--;
        }
    }

    }
    
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
int target;
cin>>target;

cout<<"maximum of all subarray of size  k\n";
triplet(ar,n,target);

    return 0;
}