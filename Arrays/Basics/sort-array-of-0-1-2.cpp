#include <vector>
#include<iostream>
using namespace std;

/*
Dutch National Flag Algorithm
------------------------------
Sort an array of 0s, 1s, and 2s in a single pass (O(n)) and constant space (O(1)).

Pointer meaning:
low  -> boundary for 0s
mid  -> current element being checked
high -> boundary for 2s
*/

void sort012(vector<int>& ar) {
    int n = ar.size();
    int low = 0, mid = 0, high = n - 1;

    cout << "\nInitial array: ";
    for (int x : ar) cout << x << " ";
    cout << "\n";

    while (mid <= high) {
        cout << "\nStep: low=" << low << ", mid=" << mid << ", high=" << high;
        cout << "\nCurrent array: ";
        for (int x : ar) cout << x << " ";
        cout << "\nChecking ar[" << mid << "] = " << ar[mid] << endl;

        if (ar[mid] == 0) {
            cout << "→ ar[mid] is 0 → swap(ar[low], ar[mid]) and increment both\n";
            int temp = ar[low];
            ar[low] = ar[mid];
            ar[mid] = temp;
            low++;
            mid++;
        } 
        else if (ar[mid] == 1) {
            cout << "→ ar[mid] is 1 → just increment mid\n";
            mid++;
        } 
        else { // ar[mid] == 2
            cout << "→ ar[mid] is 2 → swap(ar[mid], ar[high]) and decrement high\n";
            int temp = ar[mid];
            ar[mid] = ar[high];
            ar[high] = temp;
            high--;
        }

        cout << "After step: ";
        for (int x : ar) cout << x << " ";
        cout << "\n------------------------------------";
    }

    cout << "\n\n✅ Final sorted array: ";
    for (int x : ar) cout << x << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> ar(n);
    cout << "Enter array elements (only 0, 1, or 2):\n";
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    sort012(ar);

    return 0;
}


//////Explanation .///////////
// Enter size of array: 6
// Enter array elements (only 0, 1, or 2):
// 2 0 1 2 1 0

// Initial array: 2 0 1 2 1 0 

// Step: low=0, mid=0, high=5
// Current array: 2 0 1 2 1 0 
// Checking ar[0] = 2
// → ar[mid] is 2 → swap(ar[mid], ar[high]) and decrement high
// After step: 0 0 1 2 1 2 
// ------------------------------------
// Step: low=0, mid=0, high=4
// ...
// ✅ Final sorted array: 0 0 1 1 2 2
