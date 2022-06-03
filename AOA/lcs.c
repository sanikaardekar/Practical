#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m, n;
void Print_LCS(int b[m][n], char x[m], int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (b[i][j] == 0)
    {
       Print_LCS(b, x, i - 1, j - 1);
        printf("%c ", x[i - 1]);
    }
    else if (b[i][j] == 1)
    {
        Print_LCS(b, x, i - 1, j);
    }
    else
    {
        Print_LCS(b, x, i, j - 1);
    }
}
int main()
{
    char s1[100];
    char s2[100];
    printf("enter string 1\n");
    scanf("%s", &s1);
    printf("enter string 2\n");
    scanf("%s", &s2);
    // int c[100] = LCS_length(s1, s2);

    m = strlen(s1);
    n = strlen(s2);
    int b[m][n];
    int c[m + 1][n + 1];

    for (int i = 0; i <= m; i++)// 0 to =m
    {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)//0 to =n
    {
        c[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)//1 to =m
    {
        for (int j = 1; j <= n; j++)// 1 to =n 
        {
            if (s1[i - 1] == s2[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;//diagonal
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;//up
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;//left
            }
        }
    }
    // for(int i=0;i<m;i++){
    // for(int j=0;j<n;j++){
    // printf("%d ",b[i][j]);
    // }
    // printf("\n");
    // }
    Print_LCS(b, s1, m, n);
    return 0;
}
