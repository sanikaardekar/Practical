#include <stdio.h>
// int minimum(int cp, int slot[4])
// {
//     int diff[4];
//     for(int j=0;j<4;j++)
//     {
//         diff[j] = slot[j] - cp;
//     }
//     int min = 0;
//     int i;
//     for (i = 0; i < 4; i++)
//     {
//         if (min > diff[i])
//         {
//             min = slot[i];
//         }
//     }
//     return i;
// }
int main()
{
    int slots[4] = {100, 200, 300, 400};
    int process[4] = {225, 350, 150, 75};
    int low=999, temp;
    for (int i = 0; i < 4; i++) // for every process
    {

        for (int j = 0; j < 4; j++) // checking slots
        {

            if (process[i] <= slots[j] && low>slots[j])
            {
                printf("%d-%d \n", process[i], slots[j]);
                slots[j] = slots[j] - process[i];
                temp = slots[j] - process[i];
                low=temp;
                break;
            }
        }
    }
    return 0;
}