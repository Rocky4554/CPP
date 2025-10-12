#include<bits/stdc++.h>
using namespace std;

void merge(int ar[],int l,int mid,int h,int n){
    // int n=ar.size();
    int sr[n];
    int i=l,j=mid+1,k=l;
    
    while(i<=mid && j<=h){
        if(ar[i]<=ar[j]){
            sr[k]=ar[i];
            i++;
        }
        else{
            sr[k]=ar[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=h){
            sr[k++] =ar[j++];
        }
    }   
        else{
            while(i<=mid){
                sr[k++]=ar[i++];
            }
        }
    
    for (int k = l; k<=h; k++)// copying the merged sorted array to original array for further steps.
        ar[k]=sr[k];
 
}

void sort(int ar[],int l,int h,int n){
    if(l<h){
        int mid=l+(h-l)/2;//to avoid integer overflow. 
        sort(ar,l,mid,n);
        sort(ar,mid+1,h,n);
        merge(ar,l,mid,h,n);
    }

}

 void print(int ar[], int n){
    for(int i=0;i<n;i++){
          cout<<ar[i]<<endl;
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

sort(ar,0,n-1,n);
cout<<"Our sorted array\n";
print(ar,n);

    return 0;
}