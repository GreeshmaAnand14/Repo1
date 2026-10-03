
#include <stdio.h>

int main() {
    int matrix[10][10];
    int n, i, j, sum = 0;

    printf("Enter the order of the square matrix (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid matrix order.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        sum = sum + matrix[i][i];
    }

    printf("Sum of main diagonal elements = %d\n", sum);

    return 0;
}