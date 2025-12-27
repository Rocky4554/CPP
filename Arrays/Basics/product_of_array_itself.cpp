#include <vector>
#include<iostream>
using namespace std;
// Approach (Prefix & Suffix Product)

// Create output array ans

// Fill it with prefix products (product of all elements to the left)

// Then multiply with suffix products (product of all elements to the right)

// This avoids division and runs in one pass forward + one backward.

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
