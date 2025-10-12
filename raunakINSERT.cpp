#include<stdio.h>
#define MAX_SIZE 100

int main(){
		int la[MAX_SIZE]; // creating a global array of size 100. 
		int n,item,k,i;
		printf("Enter the size of array\n");//size of array.
		scanf("%d",&n);
		printf("Enter the  array\n");// values in array.
		for(int i=0;i<n;i++) {
		scanf("%d",&la[i]);
		}
	    printf("Enter position\n");//position of inserting.
		scanf("%d",&k);
		printf("Enter element to be inserted\n");//element to be inserted.
		scanf("%d",&item);
		
		if(k>n+1 && k<=0){// if pos is greatre than size of array.
            printf("invalid input");
        }
        else{
		    for(int i=n;i>=k;i--) {// runnig our loop from n-1 till position where element where to be inserted.
			la[i]=la[i-1];// moving element one step forward. 
		}
		la[k-1]=item;
        n++;
		printf("Our new array\n");// printing our new array.
		for(int i=0;i<n;i++) {
			printf("%d ",la[i]);
		}
        }
	return 0;
}


