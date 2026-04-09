#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Structure for adjacency list node
struct node
{
    int vertex;
    struct node *next;
};

struct node *adjlist[MAX];
int indegree[MAX];
int outdegree[MAX];

int main()
{
    int n, e, i, v1, v2;
    struct node *newnode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices!\n");
        return 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize
    for (i = 0; i < n; i++)
    {
        adjlist[i] = NULL;
        indegree[i] = 0;
        outdegree[i] = 0;
    }

    // Input edges
    for (i = 0; i < e; i++)
    {
        printf("Enter edge (v1 v2): ");
        scanf("%d %d", &v1, &v2);

        if (v1 < 1 || v1 > n || v2 < 1 || v2 > n)
        {
            printf("Invalid edge! Try again.\n");
            i--;
            continue;
        }

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->vertex = v2 - 1;
        newnode->next = adjlist[v1 - 1];
        adjlist[v1 - 1] = newnode;

        outdegree[v1 - 1]++;
        indegree[v2 - 1]++;
    }

    // Display adjacency list
    printf("\nAdjacency List of Directed Graph:\n");
    for (i = 0; i < n; i++)
    {
        struct node *temp = adjlist[i];
        printf("%d -> ", i + 1);

        while (temp != NULL)
        {
            printf("%d ", temp->vertex + 1);
            temp = temp->next;
        }
        printf("\n");
    }

    // Display degree
    printf("\nVertex  InDegree  OutDegree  TotalDegree\n");
    for (i = 0; i < n; i++)
    {
        printf("%6d %9d %10d %12d\n",
               i + 1,
               indegree[i],
               outdegree[i],
               indegree[i] + outdegree[i]);
    }

    return 0;
}
