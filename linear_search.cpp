#include<bits/stdc++.h>
using namespace std;

int serch(int ar[],int x,int n)
{

    for( int i=0; i<n;i++)
    {
        if(ar[i]==x){
        
        return 1;
        }
        

    }
    return -1;

}

int main(){
    int ar[]={1,2,3,4,5,6};
    int n =sizeof(ar)/sizeof(ar[0]);
    int x=4;
    cout<<search(ar,x,n);
    return 0;
}