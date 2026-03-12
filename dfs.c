//SY87 B4 bach
// DS2
//assignment 4
//Date 09-03-2026
//roll.no - 87,88

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int vertex;
    struct node * next;
};
struct node * adjlist[20];
int adj[20][20],ind[20],outd[20],n,vis[20]={0},start;
void dfs(int);
void main()
{
   int e, i,j,v1,v2;
   struct node * newnode;
   
   printf("\n Enter the number of vertices : ");
   scanf("%d",&n);
   
   if (n<=0)
   {
      printf("\n Invalid number of vertices");
   }
   printf("\n Enter the number of edges : ");
   scanf("%d",&e);
   
   for (i=0;i<=n;i++)
   {
        adjlist[i]=NULL;
        ind[i]=0;
        outd[i]=0;
        
        for (j=0;j<=n;j++)
        {
            adj[i][j]=0;
        }
    }
    for (i=0;i<e;i++)
    {
        printf("\n Enter edge (v1 v2): ");
        scanf("%d %d",&v1,&v2);
        
        if ( v1 < 1 || v1 > n || v2 < 1 || v2 > n )
        {
           printf("\n Error...Invalid edge...");
           i--;
           continue;
        }
        adj[v1-1][v2-1]=1;
        
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->vertex=v2;
        newnode->next=adjlist[v1-1];
        adjlist[v1-1]=newnode;
        
        outd[v1-1]++;
        ind[v2-1]++;
      }
     printf("\n Adjacency Matrix for Directed Graph with Degree : \n     ");
    for(j = 0; j < n; j++)
          printf("%5d", j+1);
    printf("    Indegree   Outdegree   Total Degree\n");
    for (i = 0; i < n; i++)
    {
        printf("%5d", i+1);
        for(j = 0; j < n; j++)
           printf("%5d", adj[i][j]);
        printf("%10d %10d %10d\n", ind[i], outd[i], ind[i]+outd[i]);
       
    }
     printf("\n Adjacency List : \n");
      for (i=0;i<n;i++)
      {
          struct node *temp=adjlist[i];
          printf("%d->",i+1);
          while(temp!=NULL)
          {
               printf("%d ",temp->vertex);
               temp=temp->next;
          }
          printf("\n");
      }
      printf("\nEnter The Value Of Start Vertex : ");
      scanf("%d",&start);
      dfs(start-1);
      
}

void dfs(int x)
{
    int i;
    vis[x]=1;
    printf("%d",x+1);
    for (i=0;i<n;i++)
        if (adj[x][i]==1 && vis[i]==0)
           dfs(i);
}
