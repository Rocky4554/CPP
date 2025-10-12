#include <iostream>
#include <vector>
#include <queue>
using namespace std;    

// Variety 1 
// positve elements and negetive elements are equal in the array 

vector<int> arrange(vector<int>& nums, int n ){
    vector<int> ans(n);// giving size is compusolry or the code may brake
    int pos=0, neg=1;

    for(int i=0;i<n;i++){
        if(nums[i]>0){
            ans[pos]=nums[i];
            pos+=2;
        }
        else{
            ans[neg]=nums[i];
            neg+=2;
        }
    }

    return ans;
}


int main() {
    int n, k;
    
    // Input array size
    cout << "Enter the size of the array: ";
    cin >> n;
    
    // Validate array size
    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    
    // Input array elements
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> res=arrange(nums, n);
    cout << "Resultant array:"<< endl;

    for(int it:res){
        cout<<it<<",";
    }
    
    return 0;
}