#include<bits/stdc++.h>
using namespace std;

// void swap(int a,int b){
//     int temp=a;
//     a=b;
//     b=temp;
// }

vector<int> solve(int n,vector<int> ar){
    int j = -1;
    for(int i=0;i<n;i++){
        if(ar[i]==0){
            j=i;
            break;
        }
    }
    if(j == -1) return ar;// no zero element 

    for(int i=j+1;i<n;i++){
        if(ar[i] != 0){
            int temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
            j++;
        }
        
    }
    return ar;
}

int main(){

int n;
cin>>n;
vector<int> ar(n);

cout<<"Enter array elements\n";
for(int i=0;i<n;i++){
    cin>>ar[i];
}

vector<int> ans=solve(n,ar);

for(auto it:ans){
    cout<<ans[it]<<" ";
}

    return 0;
}

// explanation 

// Initial: [1, 0, 2, 0, 3, 4]
//           ↑
//           j (first zero)

// Found non-zero (2) → swap with zero:
// [1, 2, 0, 0, 3, 4]
//              ↑
//              j moves to next zero

// Found non-zero (3) → swap with zero:
// [1, 2, 3, 0, 0, 4]
//                 ↑
//                 j moves again

// Found non-zero (4) → swap with zero:
// [1, 2, 3, 4, 0, 0]
