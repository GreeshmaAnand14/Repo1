
#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main() {
    int n;
    int dist[MAX][MAX];

    printf("Enter number of vertices: ");

    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");
    printf("Use 99999 for no edge.\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            if (scanf("%d", &x) != 1) {
                printf("Invalid input.\n");
                return 1;
            }

            if (x == 99999)
                dist[i][j] = INF;
            else
                dist[i][j] = x;
        }
    }

    // Distance from a vertex to itself is zero
    for (int i = 0; i < n; i++) {
        if (dist[i][i] > 0)
            dist[i][i] = 0;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != INF &&
                    dist[k][j] != INF) {

                    int newDist = dist[i][k] + dist[k][j];

                    if (newDist < dist[i][j]) {
                        dist[i][j] = newDist;
                    }
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            printf("Negative cycle detected!\n");
            return 0;
        }
    }

    printf("\nShortest Distance Matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
