#include<bits/stdc++.h>
using namespace std;

int insertion(int ar[],int n,int x,int pos) {
		
		if(pos>n+1 ||  pos < 0) {
            return 0;
        }
            else{
			n++;
			for(int j=n-1;j>=pos;j--) {
				ar[j]=ar[j-1];
            }
			ar[pos-1]=x;
            
		
		    return n;
        }
		
	}
	
	int main(){
		int ar[]= {1,2,3,4,5,6,8};
		int n =sizeof(ar)/sizeof(ar[0]);
		int x=7;int pos=5;
		
		n=insertion(ar,n,x,pos);
		
		cout<<"Our new array";
		for(int i=0;i<n;i++) 
		    cout<<ar[i]+" ";
	
    return 0;

}


