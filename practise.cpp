#include<bits/stdc++.h>
using namespace std;

int (int ar,int n ,int k){
    int prod=1;
    int result=0;

    int left=0;
    int rigth=0;

    while(right<n){
        prod *= nums[right];

        while(prod>=k){
            prod /=nums[left];
            left++;
        }
        result = right - left +1;
        right++;
    }
    return right;
    }

}

int main(){

  

return 0;
}