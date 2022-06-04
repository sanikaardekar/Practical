#include <stdio.h>
  
int main() 
{
      int at[10], bt[10], temp[10];
      int i, smallest, count = 0, time, n;
      double wt = 0, tt = 0, end;
      float awt, att;
      printf("Enter the Total Number of Processes: ");
      scanf("%d", &n); 
      printf("Enter Details of %d Processes", n);
      for(i = 0; i < n; i++)
      {
            printf("Enter Arrival Time:");
            scanf("%d", &at[i]);
            printf("Enter Burst Time:");
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
      }
      bt[9] = 9999;  //highest value
      for(time = 0; count != n; time++)  // count!=n
      {
            smallest = 9;    //smallest =9
            for(i = 0; i < n; i++)
            {
                  if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)  //at[i]<=timr && bt[i]<bt[small] && bt[i]>0
                  {
                        smallest = i;
                  }
            }
            bt[smallest]--;
            if(bt[smallest] == 0)
            {
                  count++;
                  end = time + 1;//end=time+1
                  wt = wt + end - at[smallest] - temp[smallest];//wt=wt+end-at-temp
                  tt = tt + end - at[smallest];//tt=tt+end-at
            }
      }
      awt = wt / n; 
      att = tt / n;
      printf("Average Waiting Time:t%lf", awt);
      printf("Average Turnaround Time:t%lf", att);
      return 0;
}