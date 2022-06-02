#include <stdio.h>
#include <string.h>

int division(int dividend[], int coeff[], int n1, int n, int rem[])
{
    int i, j, temp;
    for (i = 0; i < n1; i++)//i to n1
    {
        temp = i;
        if (dividend[i] == 1)
        {
            for (j = 0; j < n; j++)//j to n
            {
                if (dividend[temp] == coeff[j])
                {
                    dividend[temp] = 0;
                    rem[j] = 0;
                }
                else
                {
                    dividend[temp] = 1;
                    rem[j] = 1;
                }
                temp++;
            }
        }
    }
    printf("Remainder is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", rem[i]);
    }
}
int main()
{
    int n, n1, coeff[50], data[50], rem[50];
    printf("Enter number of bits of coefficients: ");
    scanf("%d", &n);
    coeff[n];
    printf("Enter coefficients of generating function: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coeff[i]);
    }
    printf("Enter number of bits of data: ");
    scanf("%d", &n1);
    data[n1];
    printf("Enter the data: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("\n");
    int dividend[n1 + n - 1];
    int arr[n - 1]; // nu
    for (int i = 0; i < n1; i++)
    {
        dividend[i] = data[i];
    }
    for (int i = n1; i < n1 + n - 1; i++)
    {
        dividend[i] = 0;
    }

    rem[n];
    int i, j;

    for (int i = 0; i < n1 + n - 1; i++)
    {
        printf("%d", dividend[i]);
    }
    printf("\n");
    int dup[n1 + n - 1]; //copying dividend in dup
    for (i = 0; i < n1 + n - 1; i++)
    {
        dup[i] = dividend[i];
    }
    division(dividend, coeff, n1, n, rem);
    if (rem[0] == 0)//
    {
        for (i = 0; i < n; i++)
        {
            dup[n1 + i] = rem[i + 1];//
        }
    }//rem this
    printf("\n");
    for (i = 0; i < n1 + n - 1; i++)
    {
        printf("%d", dividend[i]);
    }
    printf("\n");
    for (i = 0; i < n1 + n - 1; i++)
    {
        printf("%d", dup[i]);
    }
    printf("\n");
    division(dup, coeff, n1, n, rem);
    return 0;
}