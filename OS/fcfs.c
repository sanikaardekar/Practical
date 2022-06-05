#include <stdio.h>
#include <stdlib.h>
int main()
{
    int s, e, i, cur;
    printf("Enter starting of range:");
    scanf("%d", &s);
    printf("Enter ending of range:");
    scanf("%d", &e);
    int n;
    printf("Enter size of queue:");
    scanf("%d", &n);
    int queue[n];
    printf("Enter positions in queue:");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);
    printf("Enter current position:");
    scanf("%d", &cur);
    int sum = 0;
    sum = abs(cur - queue[0]);
    int diff;
    for (i = 0; i < n - 1; i++)
    {
        diff = abs(queue[i] - queue[i + 1]);
        sum = sum + diff;
    }
    printf("\nThe total head movement is:%d", sum);
    return 0;
}