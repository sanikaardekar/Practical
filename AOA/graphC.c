#include <stdio.h>
int X[10];
int m, n;
int G[10][10];
void NextValue(int k)
{
    int j;
    X[k] = (X[k] + 1) % (m + 1);  ///remmm
    if (X[k] == 0)
        return;
    for (j = 0; j < n; j++)
    {
        if (G[k][j] != 0 && X[k] == X[j])
        {
            break;
        }
    }
    if (j == n)
        return;
    else
    {
        NextValue(k);
    }
}
void mColoring(int k)
{
    NextValue(k);
    if (X[k] == 0)
        return;
    if (k == n - 1)
    {
        printf("Solution :");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", X[i]);
        }
    }
    else
    {
        mColoring(k + 1);
    }
}
int main()
{
    int edge;
    printf("Enter the no. of colours: ");
    scanf("%d", &m);
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    printf("Enter the no. of edges: ");
    scanf("%d", &edge);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
        X[i] = 0;
    }
    printf("Enter the edge vertices: \n");
    for (int i = 0; i < edge; i++)
    {
        int k, l;
        scanf("%d %d", &k, &l);
        G[k][l] = 1;
        G[l][k] = 1;
    }
    mColoring(0);
    return 0;
}
