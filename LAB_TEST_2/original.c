#include <stdio.h>

int u, v, n, i, j, k = 1;
int visited[10], weight[10][10], min, minweight = 0;
int main()
{

    printf("\n Enter the number of nodes:");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    printf("\n Enter the 9999 for infinity\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &weight[i][j]);
            if (weight[i][j] == 0)
                weight[i][j] = 999;
        }
    visited[1] = 1;
    printf("\n");
    while (k < n)
    {
        for (i = 1, min = 9999; i <= n; i++)
        {

            for (j = 1; j <= n; j++)
            {

                if (weight[i][j] < min)
                {

                    if (visited[i] != 0)
                    {
                        min = weight[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\n(%d %d) weight:%d", u, v, min);
            k++;
            minweight += min;
            visited[v] = 1;
        }
        weight[u][v] = weight[v][u] = 9999;
    }
    printf("\nTotal Minimun weight=%d", minweight);
    return 0;
}
