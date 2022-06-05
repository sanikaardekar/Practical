#include <stdio.h>
#include <stdlib.h>
int main()
{
    int s, e, n, i, j, k = 0, l = 0, temp, cur, dir, sum;
    printf("\nEnter starting of range:");
    scanf("%d", &s);
    printf("\nEnter ending of range:");
    scanf("%d", &e);
    printf("\nEnter size of queue:");
    scanf("%d", &n);
    int queue[n], arrup[n], arrdown[n];
    printf("\nEnter elements of queue:");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    printf("\nEnter current position:");
    scanf("%d", &cur);
    for (i = 0; i < n; i++)
    {
        if (queue[i] - cur > 0)
        {
            arrup[k] = queue[i];
            k++;
        }
        else if (queue[i] - cur < 0)
        {
            arrdown[l] = queue[i];
            l++;
        }
    }
    printf("\nEnter direction:");
    scanf("%d", &dir);
    if (dir == 1) // up
    {
        sum = abs(cur - arrup[k - 1]);
        sum = sum + abs(arrdown[0] - arrup[k - 1]);
    }
    else if (dir == 0) // down
    {
        sum = abs(cur - arrdown[0]);
        sum = sum + abs(arrdown[0] - arrup[k - 1]);
    }
    else
    {
        printf("Enter correct direction");
    }
    printf("\nThe total head movement is:%d", sum);
}