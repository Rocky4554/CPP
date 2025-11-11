#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int ar[n];
    printf("Enter the values of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    int temp;
    for (int i = 0; i < n - 1; i++) {
        int min = i;  // assume the first element is the minimum

        // find the index of the minimum element
        for (int j = i + 1; j < n; j++) {
            if (ar[j] < ar[min]) {
                min = j;
            }
        }

        // swap only once per iteration, after finding true min
        if (min != i) {
            temp = ar[i];
            ar[i] = ar[min];
            ar[min] = temp;
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", ar[i]);
    }

    return 0;
}
