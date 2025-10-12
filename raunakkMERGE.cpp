#include<stdio.h>

int merge(int A[],int l,int mid,int h)
{
    int n1=mid-l+1;int i;int j;
    int n2=h-mid;

    int L[n1],R[n2];

    for (i=0;i<n1;i++)
            L[i]=A[l+i];
    
       
    for( j=0;j<n2;j++)
    
     R[j]=A[mid+1+j];
    
        i=0;j=0;int k=l;

        while(i<n1&&j<n2)
        {
            if(L[i]<=R[j]){
                A[k]=L[i];
                i++;
            }
            else{
                A[k]=R[j];
                j++;
                }
                k++;
        }

            while(i<n1)
            {
                A[k]=L[i];
                i++;k++;
            }
            while(j<n2)
            {
                A[k]=R[j];
                j++;k++;
            }
}

    void sort(int A[],int l, int h){
        if(l<h){
         int mid=l+(h-l)/2;
            sort(A,l,mid);
            sort(A,mid+1,h);
            merge(A,l,mid,h);
        }
    }

        void print(int A[], int N){
            for(int i=0;i<N;i++){
                printf("%d ",A[i]);
                }
        }

int main(){
    printf("Enter the size\n");
    int N;
    scanf("%d",&N);

    int A[N];
    printf("Enetr the values in Array\n");
    for(int i=0; i<N;i++){
        scanf("%d",&A[i]);
    }

    sort(A,0,N-1);
    printf("soreted Aray\n");
    print(A,N);
 
 return 0;
}