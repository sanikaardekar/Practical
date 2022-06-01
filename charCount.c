#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, k, l, count = 0, n;
    char s[100], cs[50];
    printf("Enter the bit string : ");
    scanf("%s", s);
    n = strlen(s);
    printf("\nString is : ");
    for (i = 0; i < n; i++)

    {

        if (s[i] == s[i + 1])

        {

            count = 2;
            i++;
            while (s[i] == s[i + 1])

            {
                i++;
                count++;
            }

            if (count >= 5)

            {
                printf("$");
                if (count < 10)

                {

                    printf("0");
                }

                printf("%d%c", count, s[i]);

                i++;
            }
            else

            {

                for (j = 0; j < count; j++)
                    printf("%c", s[i]);
                i++;
            }
        }
        else

        {

            printf("%c", s[i]);
            i++;
        }
    }
}
