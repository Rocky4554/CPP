#include <iostream>
using namespace std;

void mergeArrays(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;          // last valid element in nums1
    int j = n - 1;          // last element in nums2
    int k = m + n - 1;      // last position in nums1 (end of total space)

    // Merge from the back
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If nums2 still has elements left
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int m = 3;
    int nums2[3] = {2, 5, 6};
    int n = 3;

    mergeArrays(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
