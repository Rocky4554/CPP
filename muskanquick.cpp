#include<stdio.h>

int partition(int A[],int l,int r){
    int x=A[r];
    int i=(l-1);
    for(int j=l;j<=r-1;j++){
        if(A[j]<x){
            i++;
            int temp=A[j];
            A[j]=A[i];
            A[i]=temp;
        }
    }
    int temp=A[r];
    A[r]=A[i+1];
    A[i+1]=temp;

    return (i+1);
}

void Quicksort(int A[],int l,int r){
    if(l<r){
        int q=partition(A,l,r);
        Quicksort(A,l,q-1);
        Quicksort(A,q+1,r);

    }
}

void printarray(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
        printf("\n");
    }
}

int main(){
    
    printf("enter the size\n");
    int n;
    scanf("%d",&n);
    
    int A[n]; 
    printf("enter the values of array\n");
    for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
    }
    int l=0;
    int r=n-1;
    Quicksort(A,l,r);
    printf("Our sorted array\n");
    printarray(A,n);
     
     return 0;
}