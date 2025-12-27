#include <vector>
#include<iostream>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    // Step 1: Prefix product
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = prefix;
        prefix *= nums[i];
    }

    // Step 2: Suffix product
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    return ans;
}

// Example usage
int main() {
    vector<int> nums = {1, 2, 4, 6};
    vector<int> res = productExceptSelf(nums);
    for (int x : res) cout << x << " ";
    return 0;
}
