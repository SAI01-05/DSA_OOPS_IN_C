#include <stdio.h>


void DFS(int vertex,int visited[],int m[][10],int vertices)
{
    visited[vertex]=1;
    printf("%d ",vertex);

    for (int i = 1; i <= vertices; i++)
    {
        if ((m[vertex][i]==1) && !visited[i])
        {
            DFS(i,visited,m,vertices);
        }
        
    }
    

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


    int visited[vertices];//array to track visited vertices
    for (int i = 1; i <= vertices; i++)//For make all visited vertices as not visited
    {
        visited[i]=0;
    }
    DFS(1,visited,m,vertices);
}