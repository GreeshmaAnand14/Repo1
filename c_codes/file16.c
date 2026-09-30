
#include <stdio.h>

int main() {
    int matrix[10][10];
    int n, i, j;
    int identity = 1;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1) {
                identity = 0;
            }

            if (i != j && matrix[i][j] != 0) {
                identity = 0;
            }
        }
    }

    if (identity == 1) {
        printf("The matrix is an identity matrix.\n");
    } else {
        printf("The matrix is not an identity matrix.\n");
    }

    return 0;
}