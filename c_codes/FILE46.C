
#include <stdio.h>

int main()
{
    int a[20][20], visited[20] = {0};
    int queue[20];
    int n, i, j, start;
    int front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while(front < rear)
    {
        int current = queue[front++];

        printf("%d ", current);

        for(i = 0; i < n; i++)
        {
            if(a[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}
