#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> ar,int target){
    int m=ar.size();// it gives no of rows.
    int n=ar[0].size();// it gives of columns.(important)

    int l=0;int h=(n*m)-1;
     while(l<=h){
         int mid= l+(h-l)/2;

         if(ar[mid/n][mid%n]==target){
             return true;
         }
         else if(ar[mid/n][mid%n]<target){
             l=mid+1;
         }
         else{
             h=mid-1;
         }
     }
     return false;

}

int main(){
    vector<vector<int>> ar{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target =13;

    if(searchMatrix(ar,target)){
        cout<<"Element found\n";
    }
    else{
        cout<<"Element not found\n";
    }

    return 0;
}