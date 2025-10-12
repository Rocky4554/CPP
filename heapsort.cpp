#include<stdio.h>

void swap(int *s, int *p){
    int temp= *s;
    *s=*p;
    *p=temp;

}

    void heapify(int ar[], int n,int i){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n and ar[l] > ar[largest] )
          largest = l;
        
        if(r <n and ar[r] > ar[largest] )
        largest = r;
        if(largest != i )
        {
        swap(&ar[i],&ar[largest]);
        heapify (ar,n,largest);
        }
    }   

 
  void heapsort(int ar[],int n){

        for(int i=n/2-1;i>=0;i--)
        heapify(ar,n,i);
    
        for(int i=n-1;i>0;i--){
            swap(&ar[0],&ar[i]);
            heapify(ar,i,0);
        }

    }

    void print(int ar[],int n){
    
        for(int i=0;i<n;i++){
        printf("%d",ar[i]);
        printf("\n");
        }
    }

int main(){
    printf("enter the size \n");
    int n;
    scanf("%d",&n);

    int ar[n];
    printf("enter the elements in array \n");
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }

    heapsort(ar,n);
    printf("sorted array\n");
    print(ar,n);

    return 0;

}