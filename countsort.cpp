#include<stdio.h>
//#include<cstdlib> (lib for using malloc function.)
#include<limits.h>// lib for using INT_MAX.

int maximum(int ar[],int n){// finding maximum element in array.
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(ar[i]>max){
        max=ar[i];
        }
    }
    return max;

}
void sort(int ar[],int n){
    
    int new_size=maximum(ar,n);
        
    // int *count = (int *) malloc((new_size+1)*sizeof(int)); 
    int count[new_size+1];//creting new array of size max elenent in given aray.

    for(int i=0;i< new_size+1;i++){//filling new array count with 0.
    count[i]=0;
    }
    
    for(int i=0;i<n;i++){//incrementing corresponding  index in count array.
    count[ar[i]]=count[ar[i]] + 1;
    }
    
   int k=0;//counter for count array.
   int l=0;// counter for given array.
    
     while(k<new_size+1){//
        if(count[k]>0){
        ar[l]=k;
        count[k]=count[k]-1;
        l++;
        }
        else{
        k++;
        }
     }
}

void printarray(int ar[],int n){
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
    printf("enter the array \n");
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }

    sort(ar,n);
    printf("sorted array\n");
    printarray(ar,n);
    
    return 0; //  it extra space(creats new array) ,time complexity =O(m+n)(sorts in linear time)
}