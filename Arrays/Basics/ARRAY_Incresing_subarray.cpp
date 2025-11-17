#include<bits/stdc++.h>
using namespace std;


    int solve(int n, int ar[]) {
        int ar1[n];
        int j = 0;
        ar1[j] = ar[0];
        for (int i = 1; i <n; i++) {
            if (ar1[j] < ar[i]) {
                j++;
                ar1[j] = ar[i];
            } else {
                ar1[j] = ar[i];

            }
        }
        return j + 1;
    }

    int main() {
        
        int n;
        cin>>n; 
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin>>ar[i];
        }
        cout<<solve(n, ar);

    return 0;
    }


