#include<stdio.h>

int main()
{

    printf("enter the size of array\n");
    int n;
    scanf("%d",&n);

    int ar[n];
    printf("enter the values of array\n");
    for(int i=0; i<n;i++){
    scanf("%d",&ar[i]);
    }   

    int temp;int i;int j;
        for( i=0; i<n-1;i++){
             int min= i ;
;            for( j=i+1;j<n;j++){
                if(ar[j]<ar[i]){

                    min = j;
                
                    temp = ar[j];
                    ar[j]=ar[i];
                    ar[i]= temp;
                }  
             
            } 
        }
     
             
    printf("sorted array\n");
    for(int i=0; i<n;i++)
    {
    printf("%d",ar[i]);
    printf("\n");
    }


    return 0;
}


