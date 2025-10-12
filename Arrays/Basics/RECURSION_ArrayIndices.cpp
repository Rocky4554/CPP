#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> ar,int index,int count,int target){
    if(index==ar.size()){
        vector<int> ans(count);
        return ans;
    }

    if(ar[index]==target){
        vector<int> iarr=solve(ar,index+1,count+1,target);// we are storing because we are returning something in our main function.
        iarr[count]=index;
        return iarr;
    }else{
        
     vector<int> iarr=solve(ar,index+1,count,target);
        return iarr;
    }
}
int main(){
    vector<int> ar={2,3,6,9,8,3,2,3,6,4};
    int target=3;
    int count=0;
    vector<int> fs=solve(ar,0,count,target);

    for(int i=0;i<fs.size();i++){
        cout<<fs[i]<<" ";
    }

    return 0;
}