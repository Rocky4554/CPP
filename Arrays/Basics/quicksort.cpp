#include<stdio.h>
 
    int partition(int ar[],int l,int h){
        
        int pivot=ar[h],j=(l-1);
        for(int i=l;i<=h-1;i++){
            if(ar[i]<pivot){
           j +=1;
           int temp=ar[i];
           ar[i]=ar[j];
           ar[j]=temp;
            }
       }
       int temp=ar[h];
       ar[h]=ar[j+1];
       ar[j+1]=temp;     
       return (j+1);
   }

   void quicksort(int ar[],int l, int h){
       if(l<h){
           int q=partition(ar,l,h);
           quicksort(ar,l,q-1);
           quicksort(ar,q+1,h);
       }
   }

   void print(int ar[], int n){
       for(int i=0;i<n;i++){
           printf("%d",ar[i]);
           printf("\n");
       }
   }
   
int main(){

    printf("enter the size\n");
    int n;
    scanf("%d",&n);
    
    int ar[n]; 
    printf("enter the values of array\n");
    for(int i=0;i<n;i++){
    scanf("%d",&ar[i]);
    }

    quicksort(ar,0,n-1);
    printf("Our sorted array\n");
    print(ar,n);
     
     return 0;
   }

        
    
      


   