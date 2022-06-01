/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 100

int G[9][9]= {
                {0,4,0,0,0,0,0,8,0},
                {4,0,8,0,0,0,0,11,0},
                {0,8,0,7,0,0,0,0,2},
                {0,0,7,0,9,14,0,0,0},
                {0,0,0,9,0,10,0,0,0},
                {0,0,4,14,10,0,2,0,0},
                {0,0,0,0,0,2,0,1,6},
                {8,11,0,0,0,0,1,0,7},
                {0,0,2,0,0,0,6,7,0}
                 };
   
int extmin(int d[9], int spt[9])
{
    int dmin=MAX;
    int min_index;
    for(int i=0;i<9;i++)
    {
    if(d[i]<=dmin && spt[i]!=1)
    {
        dmin=d[i];
        min_index=i;
        }
    }
    return min_index;
}
int main()
{               
    
    int d[9];
    int prnt[9];
    int spt[9];
    for(int i=0;i<9;i++)
    {
        d[i] =MAX;
        spt[i] = 0;
        prnt[i]=-1;
    }
    d[0]=0;
    for(int i=0;i<9;i++)
    {
        int j = extmin(d,spt);
        spt[j] = 1;
        for(int k=0;k<9;k++)
        {
            if(G[j][k]!=0 && spt[k]!=1 && d[k]>G[j][k])
            {
                d[k]=G[j][k];
                prnt[k]=j;
            }
        }
    }
    int total=0;
    printf("node distance parent\n");
    for(int i=0;i<9;i++)
    {
        total = total+d[i];
        printf("%d %d %d\n",i,d[i],prnt[i]+1);
    }
    printf("total cost %d",total);
    return 0;
}
