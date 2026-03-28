#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cost[6][6] = {{0, 2, 999, 999, 999, 4}, {2, 0, 8, 999, 999, 3}, {999, 8, 0, 6, 1, 999}, {999, 999, 6, 0, 12, 999}, {999, 999, 1, 12, 0, 2}, {4, 3, 999, 999, 2, 0}};
    int z, i, j, a, b, u, v;
    int visited[6] = {0}, min, mincost = 0;
    visited[0] = 1;
    for (z = 0; z < 6; z++)
    {
        for (i = 0, min = 999; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                
                if (cost[i][j] == 0)
                {
                    cost[i][j] = 999;
                }
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\n Edge %d:(%d %d) cost:%d", z + 1, a + 1, b + 1, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n minimum cost=%d", mincost);
    
}