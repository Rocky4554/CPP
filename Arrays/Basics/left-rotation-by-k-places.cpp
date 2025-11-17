#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> leftrotate_better(vector<int> &arr, int n, int d) {
d = d % n;

int temp [d] ;

for (int i = 0; i < d; i++)
{
temp [i] = arr[i] ;
}

for (int i = d; i < n; i++){
arr[i - d] = arr[i] ;
}

for (int i = n - d; i < n; i++){
arr[i] = temp[i - (n-d) ] ;
}
return arr;

}

int main() {
    int n,d;
    
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

    cout << "Enter how many times to rotate ";
    cin >> d;
    
    // Call arrange function
    vector<int> res = leftrotate_better(nums, n,d);
    
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

