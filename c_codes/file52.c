
#include <stdio.h>

int main()
{
    int rows, cols;
    int dp[20][20];
    int i, j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > 20 || cols > 20)
    {
        printf("Invalid grid size!\n");
        return 0;
    }

    // First row and first column have one path
    for (i = 0; i < rows; i++)
        dp[i][0] = 1;

    for (j = 0; j < cols; j++)
        dp[0][j] = 1;

    // Calculate number of paths
    for (i = 1; i < rows; i++)
    {
        for (j = 1; j < cols; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    printf("\nNumber of unique paths: %d\n", dp[rows - 1][cols - 1]);

    printf("\nDP Table:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%d ", dp[i][j]);

        printf("\n");
    }

    return 0;
}
