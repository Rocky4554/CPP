#include <iostream>
#include <vector>
using namespace std;

// Function to partition array with positive numbers (including zero) on left and negative on right
vector<int> arrange(vector<int>& arr, int n) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        // If both elements are negative, move left pointer
        if (arr[left] < 0 && arr[right] < 0) {
            left++;
        }
        // If left is positive (or zero) and right is negative, swap them
        else if (arr[left] >= 0 && arr[right] < 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        // If both elements are positive (or zero), move right pointer
        else if (arr[left] >= 0 && arr[right] >= 0) {
            right--;
        }
        // If left is negative and right is positive (or zero), both are in correct position
        else {
            left++;
            right--;
        }
    }
    
    return arr;
}

int main() {
    int n;
    
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
    
    // Call arrange function
    vector<int> res = arrange(nums, n);
    
    // Output the result
    cout << "Resultant array: ";
    if (res.empty()) {
        cout << "Empty array" << endl;
    } else {
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i < res.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    
    return 0;
}