#include<stdio.h>

int main(){
    printf("enter the size \n");
    int n;
    scanf("%d",&n);

    int ar[n];
    printf("enter the values in array\n");
    for(int i=0;i<n;i++){
    scanf("%d",&ar[i]);
    }

    for(int i=1;i<n;i++){
       int pick=ar[i];
        int j=i-1;
        while(j>=0 && pick<ar[j]){
            ar[j+1]=ar[j];
            j--;
            ar[j+1]=pick;
        }
     }

    printf("sorted array\n");
    for(int i=0;i<n;i++){
        printf("%d",ar[i]);
        printf("\n");
    }

     return 0;
}