#include <stdio.h>
int w[]={2,3,4,5}, m=7, x[]={0,0,0,0};

void sumofsubsets(int s, int k, int r)
{
    x[k] = 1;
    if(s+w[k]==m)
    {
        for(int t=0;t<k;t++)
        {
            printf("%d ",x[t]);
        }
    }
    else if(s+w[k]+w[k+1]<=m)
    {
        sumofsubsets(s+w[k],k+1,r-w[k]);
    }
    if((s+r-w[k]>=m) && (s+w[k+1]<=m))
    {
        x[k] = 0;
        sumofsubsets(s,k+1,r-w[k]);
    }
}
int main()
{
   sumofsubsets(0,0,14);

    return 0;
}