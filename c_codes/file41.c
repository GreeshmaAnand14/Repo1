
#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main() {
    int n, graph[MAX][MAX];
    int dist[MAX], visited[MAX] = {0};
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter adjacency matrix (0 means no edge):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] < 0) {
                printf("Negative weights are not allowed.\n");
                return 1;
            }
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        // Find nearest unvisited vertex
        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1 || dist[u] == INF)
            break;

        visited[u] = 1;

        // Relax neighboring edges
        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v]) {
                if (dist[u] <= INF - graph[u][v] &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", start);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("To %d: Unreachable\n", i);
        else
            printf("To %d: %d\n", i, dist[i]);
    }

    return 0;
}
