#include<stdio.h>



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
        int temp=ar[i];
        ar[i]=ar[largest];
        ar[largest]=temp;
        heapify (ar,n,largest);
        }
    }   

 
  void heapsort(int ar[],int n){

        for(int i=n/2-1;i>=0;i--)
        heapify(ar,n,i);
    
        for(int i=n;i>0;i--){
            int temp=ar[0];
            ar[0]=ar[i];
            ar[i]=temp;
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