
#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char s1[MAX], s2[MAX];
    int dp[MAX][MAX];
    int m, n;
    int i, j;
    char lcs[MAX];

    printf("Enter first string: ");
    scanf("%99s", s1);

    printf("Enter second string: ");
    scanf("%99s", s2);

    m = strlen(s1);
    n = strlen(s2);

    // Initialize first row and column
    for (i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Build the DP table
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1]
                           ? dp[i - 1][j]
                           : dp[i][j - 1];
            }
        }
    }

    // Reconstruct the LCS
    i = m;
    j = n;

    int index = dp[m][n];
    lcs[index] = '\0';

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("\nLongest Common Subsequence: %s\n", lcs);
    printf("Length of LCS: %d\n", dp[m][n]);

    return 0;
}

