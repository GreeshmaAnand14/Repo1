#include <stdio.h>

int main() {
    int n, i, search;
    int arr[100];
    int left, right, mid;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers in sorted order:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &search);

    left = 0;
    right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == search) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (arr[mid] < search) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (found == 0) {
        printf("Element not found.\n");
    }

    return 0;
}