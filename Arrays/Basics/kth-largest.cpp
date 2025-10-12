#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Preview 
// Array: [3, 2, 1, 5, 6, 4], k=2
// Step 1: Push 3 → Heap: {3}
// Step 2: Push 2 → Heap: {2, 3}
// Step 3: Push 1 → Heap: {1, 3, 2} → Pop 1 → Heap: {2, 3}
// Step 4: Push 5 → Heap: {2, 3, 5} → Pop 2 → Heap: {3, 5}
// Step 5: Push 6 → Heap: {3, 5, 6} → Pop 3 → Heap: {5, 6}
// Step 6: Push 4 → Heap: {4, 6, 5} → Pop 4 → Heap: {5, 6}
// Final Heap: {5, 6}
// Kth Largest Element (k=2): 5

int findKthLargest(vector<int>& nums, int k) {
    // Create a min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Iterate through the array
    for (int num : nums) {
        minHeap.push(num);
        // If heap size exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // The top of the heap is the kth largest element
    return minHeap.top();
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
    
    // Input k
    cout << "Enter the value of k: ";
    cin >> k;
    
    // Validate k
    if (k <= 0 || k > n) {
        cout << "Invalid value of k!" << endl;
        return 1;
    }
    
    // Find and output the kth largest element
    cout << "Kth largest element: " << findKthLargest(nums, k) << endl;
    
    return 0;
}