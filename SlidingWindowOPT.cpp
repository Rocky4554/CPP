#include<bits/stdc++.h>
using namespace std;
// Question statement .....finding max in window of three in an array 
vector<int> maxinSub(vector<int>& nums,int k){
// int n =nums.size();
int i=0,j=0;
vector<int> v;
queue<int> q;
while(j<nums.size()){
    // while(q.empty()){
    // q.push(nums[j]);
    // // }

    while(!q.empty() && q.front()<nums[j]){
        q.pop();
    }
    q.push(nums[j]);

    if(j-i+1 < k){
    j++;
    }

    else if(j-i+1 == k){ 
        v.push_back(q.front());
        if(nums[i]==q.front()){
            q.pop();
            
        }
        i++;j++;
    }

}
return v;
}

int main(){
    vector<int> nums{1,3,1,2,0,5};
    int k = 3;
    vector<int> fc;
    fc=maxinSub(nums,k);

    for(int i=0;i<fc.size();i++){
        cout<<fc[i]<<" ";
    }
    return 0;
}