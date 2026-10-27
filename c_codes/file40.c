#include <stdio.h>

#define MAX 101
#define INF 9999

int main() {
    int cost[MAX][MAX], visited[MAX] = {0};
    int n, e;
    int i, j, k;
    int min, u, v;
    int mincost = 0, count = 0;

    scanf("%d %d", &n, &e);

    if (n <= 0 || e <= 0 || n >= MAX) {
        printf("-1");
        return 0;
    }

    // Initialize matrix
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cost[i][j] = INF;
        }
    }

    // Read edges
    for (k = 0; k < e; k++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        cost[a][b] = w;
        cost[b][a] = w;
    }

    visited[1] = 1;

    while (count < n - 1) {
        min = INF;
        u = -1;
        v = -1;

        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (v == -1) {
            printf("-1");
            return 0;
        }

        visited[v] = 1;
        mincost += min;
        count++;
    }

    printf("%d", mincost);

    return 0;
}