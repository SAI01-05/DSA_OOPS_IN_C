#include <stdio.h>

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

    printf("vertex indegree outdegree totaldegree\n");
    for (int i = 1; i <= vertices; i++)
    {
        int in = 0;
        int out = 0;
        int total = 0;

        for (int j = 1; j <= vertices; j++)
        {
            if (m[i][j] == 1)
            {
                out++;
            }
            if (m[j][i] == 1)
            {
                in++;
            }
        }
        total=in+out;
        printf("%d\t%d\t%d\t%d\n", i, in, out, total);
    }
}