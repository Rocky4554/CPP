#include<bits/stdc++.h>
using namespace std;

// concept here 
//  0 1 2 3 4 5 6 7-- indexes
//  1,2,3,4,5,6,7,8--values in array 
//  1,1,1,1,1,1,1,1-- diff(indexes - values) so if there is any missing no the diff are not 1 always more than one .
// so we check the diff like ar[l]-l and a[h]-h id the diff is greater than the mid we go the right else less or equal we go
//the left and return always ar[mid]+1 ;

int missing(int ar[],int n){
    int l=0;int h=n-1;
    int mid;
    while((h-l)>1){
        mid=l+(h-l)/2;
        cout<< "mid:"<<mid<< endl;
        if((ar[l]-l)!=(ar[mid]-mid)){
        h=mid;
        }
        else if ((ar[h]-h)!=(ar[mid]-mid)){
            l=mid;
        }
            
        
        return (ar[mid]+1);
    }

}
int main(){

    int ar[]={1,2,3,5,7,8};
    int n =sizeof(ar)/sizeof(ar[0]);

    cout<<"required numbers\n";
    cout<<missing(ar,n);
 
  return 0;
}
