#include<bits/stdc++.h>
using namespace std;

int merge(int ar[],int l,int mid,int h)
{
    int n1=mid-l+1;int i;int j;
    int n2=h-mid;

    int L[n1],R[n2];

    for (i=0;i<n1;i++)
            L[i]=ar[l+i];//filling the new array
    
       
    for( j=0;j<n2;j++)
    
     R[j]=ar[mid+1+j];//filling the second array
    
        i=0;j=0;int k=l;

        while(i<n1&&j<n2)// mergeing 
        {
            if(L[i]<=R[j]){
                ar[k]=L[i];
                i++;
            }
            else{
                ar[k]=R[j];
                j++;
                }
                k++;
        }

            while(i<n1)
            {
                ar[k]=L[i];
                i++;k++;
            }
            while(j<n2)
            {
                ar[k]=R[j];
                j++;k++;
            }
}

    void sort(int ar[],int l, int h){
        if(l<h){
         int mid=l+(h-l)/2;
            sort(ar,l,mid);
            sort(ar,mid+1,h);
            merge(ar,l,mid,h);
        }
    }

        void print(int ar[], int n){
            for(int i=0;i<n;i++){
                printf("%d",ar[i]);
                printf("\n");
            }
        }

int main(){
    printf("Enter the size\n");
    int n;
    scanf("%d",&n);

    int ar[n];
    printf("Enter the values in array\n");
    for(int i=0; i<n;i++){
        scanf("%d",&ar[i]);
    }

    sort(ar,0,n-1);
    printf("soreted array\n");
    print(ar,n);
 
 return 0;
}