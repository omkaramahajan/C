#include <stdio.h>
#define MAX 20

int graph[MAX][MAX], visited[MAX], stack[MAX];
int n, top = -1;

void dfs(int v)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }

    stack[++top] = v;
}

void topologicalSort()
{
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
        }
    }

    printf("Topological Order:\n");
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    topologicalSort();
    return 0;
}
