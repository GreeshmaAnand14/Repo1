#include <stdio.h>

#define MAX_VERTICES 10

// Adjacency Matrix to store the graph
int graph[MAX_VERTICES][MAX_VERTICES];
// Array to track visited nodes
int visited[MAX_VERTICES];
int vertices;

// Recursive function for DFS traversal
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1; // Mark the node as visited

    for (int i = 0; i < vertices; i++) {
        // If an edge exists and the adjacent vertex hasn't been visited yet
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i); // Recursive call
        }
    }
}

int main() {
    int edges, src, dest;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph matrix and visited array to 0
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges and build the adjacency matrix
    printf("Enter edges (source destination) using 0-indexed values:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // Omit this line if you want a Directed Graph
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(startVertex);
    printf("\n");

    return 0;
}
