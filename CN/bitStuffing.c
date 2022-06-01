#include <stdio.h>
#include <string.h>
void main()
{
    int a[20], b[30], i, j, k, count, n;
    printf("Enter the size of frame : ");
    scanf("%d", &n);
    printf("Enter the bits in the frame : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    i = 0;
    count = 1;
    j = 0;
    while (i < n)
    {
        if (a[i] == 1)
        {
            b[j] = a[i];
            for (k = i + 1; a[k] == 1 && k < n && count < 5; k++)
            {
                j++;
                b[j] = a[k];
                count++;
                if (count == 5)
                {
                    j++;
                    b[j] = 0;
                }
                i = k;
            }
        }
        else
        {
            b[j] = a[i];
        }
        i++;
        j++;
    }
    printf("String after bit stuffing is : ");
    for (i = 0; i < j; i++)
    {
        printf("%d", b[i]);
    }
}
