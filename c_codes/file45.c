
#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity;
    int weight[MAX], value[MAX];
    int dp[MAX + 1][MAX + 1];

    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > MAX) {
        printf("Invalid number of items.\n");
        return 1;
    }

    printf("Enter knapsack capacity: ");
    if (scanf("%d", &capacity) != 1 ||
        capacity < 0 || capacity > MAX) {
        printf("Invalid capacity.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);

        if (scanf("%d %d", &weight[i], &value[i]) != 2 ||
            weight[i] <= 0 || value[i] < 0) {
            printf("Invalid item details.\n");
            return 1;
        }
    }

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = 0;
        }
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            // Exclude current item
            dp[i][w] = dp[i - 1][w];

            // Include current item if it fits
            if (weight[i - 1] <= w) {
                int include = value[i - 1] +
                    dp[i - 1][w - weight[i - 1]];

                dp[i][w] = max(dp[i][w], include);
            }
        }
    }

    printf("\nMaximum value = %d\n", dp[n][capacity]);

    // Find selected items
    int w = capacity;
    printf("Selected items: ");

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= weight[i - 1];
        }
    }

    printf("\n");
    return 0;
}
