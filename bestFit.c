#include<stdio.h>
int main()
{
    int block_size[20],process_size[20],i,j,block_num,process_num;
    int allocation[10];
    for(i=0;i<10;i++)
    {
        allocation[i]=-1;
    }
    printf("Enter the number of blocks:\n");
    scanf("%d",&block_num);
    for(i=0;i<block_num;i++)
    {
        printf("Enter the block size:\n");
        scanf("%d",&block_size[i]);
    }
    printf("Enter the number of process:\n");
    scanf("%d",&process_num);
    for(i=0;i<process_num;i++)
    {
        printf("Enter the process size:\n");
        scanf("%d",&process_size[i]);
    }
    for (int i = 0; i < process_num; i++)
    { 
        int indexPlaced = -1;
        for (int j = 0; j < block_num; j++)
        { 
            if (block_size[j] >= process_size[i])
            {
               
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (block_size[j] < block_size[indexPlaced])
                    indexPlaced = j;
            }
        }
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            block_size[indexPlaced] -= process_size[i];
        }
    }
    printf("\nProcess Num\tProcess Size\tBlock Num");
    for(i=0;i<process_num;i++)
    {
        printf("\n%d\t\t%d\t\t",i+1,process_size[i]);
        if(allocation[i]!=-1)
            printf("%d\n",allocation[i]+1);
        else
            printf("Not Allocated");
    }
}