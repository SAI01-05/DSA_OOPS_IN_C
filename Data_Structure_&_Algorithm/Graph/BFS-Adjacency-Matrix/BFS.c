#include <stdio.h>


void BFS(int startVertex,int vertices,int m[][10])
 {
    int visited[startVertex];
    int queue[vertices];
    int front=0,rear=-1;
    for (int i = 1; i <= vertices; i++)
    {
        visited[i]=0;
    }
    
    visited[startVertex]=1;
    queue[++rear]=startVertex;
    while (front<=rear)
    {
        int currentVertex=queue[front++];
        printf("%d ",currentVertex);
        for (int i = 1; i <= vertices; i++)
        {
            if (m[currentVertex][i]==1 && !visited[i])
            {
                visited[i]=1;
                queue[++rear]=i;
            }
            
        }
        
    }
    printf("\n");

 }





int main()
{
    int m[10][10], vertices, in, out;
    printf("Enter how many vertices you want\n");
    scanf("%d", &vertices);
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            printf("is there is edge between %d -> %d\n", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    // Display adjacency matrix
    printf("The adjacency matrix is as below\n");
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    // int m[6][6]={{0,1,1,0,0,0},{1,0,0,1,1,0},{1,0,0,0,0,1},{0,1,0,0,0,0,},{0,1,0,0,0,0,},{0,0,1,0,0,0,}};
    BFS(1,vertices,m);
   
}