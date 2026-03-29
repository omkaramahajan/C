#include<stdio.h>
#define MAX 20
#define INF 999

int cost[MAX][MAX];
int n;

void floydWarshall()
{
    int i, j, k;

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    printf("\nAll Pairs Shortest Path Matrix:\n\n");

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
}

int main()
{
    int e, i, j, v1, v2, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }

    for(i = 1; i <= e; i++)
    {
        printf("Enter edge (v1 v2 weight): ");
        scanf("%d %d %d", &v1, &v2, &w);

        cost[v1][v2] = w;
        // remove below line if graph is directed
        cost[v2][v1] = w;
    }

    printf("\nInitial Cost Matrix:\n\n");

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

    floydWarshall();

    return 0;
}
