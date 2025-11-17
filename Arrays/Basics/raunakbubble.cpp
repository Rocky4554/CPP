#include<stdio.h>

void bubble(int data[],int n){
   int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(data[j]>data[j+1]){
            temp=data[j+1];
            data[j+1]=data[j];
            data[j]=temp;
            }
        }
    }   
} 
void printarray(int data[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",data[i]);
    }
}          
 
int main(){
    printf("enter the size\n");
    int n;
    scanf("%d",&n);

    int data[n];
    printf("enter the values in array\n");
    for(int i=0; i<n;i++){
    scanf("%d",&data[i]);
    }
   
    bubble(data,n);
    printf("Sorted array\n");
    printarray(data,n);
    
    return 0;
}