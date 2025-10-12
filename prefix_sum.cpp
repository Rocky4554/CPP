#include<bits/stdc++.h>
using namespace std;

int* prefix(int ar[],int n){//making thr fuction name as [pointer]
    static int pre[4];// we can only store constant variable here.ex...2,4,5.
    pre[0]=ar[0];
    for(int i=1;i<n;i++){
        pre[i]= pre[i-1] + ar[i];
        }
        return pre;;
}

int main()
{
    int ar[]={10,4,16,20};
    int n =4;
    int* ptr = prefix(ar,n);// storing the function name in pointer.
    cout<<" the prefix array\n";
    
    for(int i=0;i<n;i++){  // printing the pointer .
            cout<<ptr[i]<<"\t";// \t give space to pointer.
    }
    return 0;
}