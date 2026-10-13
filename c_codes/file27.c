
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0;
    int *arr;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 ||
        (size_t)n > (size_t)-1 / sizeof(int)) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    arr = malloc((size_t)n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);

    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);

    free(arr);
    return 0;
}
