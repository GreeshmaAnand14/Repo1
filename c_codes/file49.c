
#include <stdio.h>

#define INF 99999

struct Edge
{
    int source;
    int destination;
    int weight;
};

int main()
{
    struct Edge edges[100];
    int distance[20];
    int vertices, edge_count;
    int source;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edge_count);

    if (vertices <= 0 || vertices > 20 ||
        edge_count < 0 || edge_count > 100)
    {
        printf("Invalid graph size!\n");
        return 0;
    }

    printf("Enter source, destination and weight:\n");

    for (i = 0; i < edge_count; i++)
    {
        scanf("%d %d %d",
              &edges[i].source,
              &edges[i].destination,
              &edges[i].weight);

        if (edges[i].source < 0 ||
            edges[i].source >= vertices ||
            edges[i].destination < 0 ||
            edges[i].destination >= vertices)
        {
            printf("Invalid edge!\n");
            return 0;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= vertices)
    {
        printf("Invalid source vertex!\n");
        return 0;
    }

    for (i = 0; i < vertices; i++)
        distance[i] = INF;

    distance[source] = 0;

    // Relax all edges V-1 times
    for (i = 1; i < vertices; i++)
    {
        int updated = 0;

        for (j = 0; j < edge_count; j++)
        {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            if (distance[u] != INF &&
                distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                updated = 1;
            }
        }

        if (!updated)
            break;
    }

    // Check for negative-weight cycle
    for (j = 0; j < edge_count; j++)
    {
        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;

        if (distance[u] != INF &&
            distance[u] + w < distance[v])
        {
            printf("Negative weight cycle detected!\n");
            return 0;
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < vertices; i++)
    {
        if (distance[i] == INF)
            printf("Vertex %d : INF\n", i);
        else
            printf("Vertex %d : %d\n", i, distance[i]);
    }

    return 0;
}
