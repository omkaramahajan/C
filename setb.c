#include<stdio.h>
#define MAX 20
#define INF 999

int cost[MAX][MAX], dist[MAX], visited[MAX];
int n;

void dijkstra(int start)
{
    int i, j, u, min;

    for(i = 1; i <= n; i++)
    {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 1; j <= n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 1; j <= n; j++)
        {
            if(!visited[j] && (dist[u] + cost[u][j] < dist[j]))
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest Distances from vertex %d:\n", start);

    for(i = 1; i <= n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main()
{
    int e, i, j, v1, v2, w, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cost[i][j] = INF;
    }

    for(i = 1; i <= e; i++)
    {
        printf("Enter edge (v1 v2 weight): ");
        scanf("%d %d %d", &v1, &v2, &w);

        cost[v1][v2] = w;
        // cost[v2][v1] = w; // Uncomment for undirected graph
    }

    printf("\nAdjacency Matrix (Cost Matrix):\n\n");

    printf("     ");
    for(i = 1; i <= n; i++)
        printf("%4d", i);
    printf("\n");

    for(i = 1; i <= n; i++)
    {
        printf("%4d", i);

        for(j = 1; j <= n; j++)
        {
            if(cost[i][j] == INF)
                printf("%4d", 0);
            else
                printf("%4d", cost[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter source vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}
