#include <stdio.h>
#define MAX 99999

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

void flloyd_warshall(int w[1000][1000], int n)
{
    int d[1000][1000];
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = w[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
            }
        }
    }
    printf("The following matrix shows the shortest distances between every pair of vertices: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == MAX)
            {
                printf("%7s", "INF");
            }
            else
            {
                printf("%7d", d[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    int n;
    scanf("%i", &n);
    printf("Enter the adjacency matrix:\n");
    int d[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            scanf("%i", &tmp);
            if (tmp != MAX)
            {
                d[i][j] = tmp;
            }
            else
            {
                d[i][j] = MAX;
            }
        }
    }
    flloyd_warshall(d, n);
    return 0;
}