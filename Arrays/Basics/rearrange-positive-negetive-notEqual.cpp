#include <iostream>
#include <vector>
#include <queue>
using namespace std;    

// Variety 1 
// positve elements and negetive elements are not equal in the array
//case 1: pos > neg || case 2 : pos < neg

vector<int> arrange(vector<int>& nums, int n ){
    vector<int> pos ,neg;
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            pos.push_back(nums[i]);
        }
        else{
            neg.push_back(nums[i]);
        }
    }

    if(pos.size() > neg.size()){
        for (int i=0 ;i<neg.size();i++){
            nums[i*2]=pos[i];
            nums[i*2+1]=neg[i];
        }

        int index= neg.size() * 2;
        for(int i=neg.size();i<pos.size();i++){
            nums[index]=pos[i];
            index++;
        }

    }
    else{
         for (int i=0 ;i<pos.size();i++){
            nums[i*2]=pos[i];
            nums[i*2+1]=neg[i];
        }

        int index= pos.size() * 2;
        for(int i=pos.size();i<neg.size();i++){
            nums[index]=neg[i];
            index++;
        }

    }

    return nums;
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