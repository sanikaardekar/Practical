#include <stdio.h>
int main(){

int at[10],bt[10],temp[10], count = 0, time=0, smallest=9, n;
double wt = 0, tat = 0, end;
float awt, atat;
printf("enter number of precesses\n");
scanf("%d",&n);
printf("enter arrival and burst time of processes\n");
for(int i=0;i<n;i++){
printf("enter arrival time\n");
scanf("%d",&at[i]);
printf("enter burst time\n");
scanf("%d",&bt[i]);
temp[i]=bt[i];
}

bt[9]=9999;
for(time=0;count!=n;time++){
smallest = 9;
for(int i=0;i<n;i++){
if(at[i]<=time && bt[smallest]>bt[i] && bt[i]>0){
smallest=i;
}
}
bt[smallest]--;
if(bt[smallest]==0){
count++;
end=time+1;
wt=wt+end-at[smallest]-temp[smallest];
tat=tat+end-at[smallest];
}
}
awt=wt/n;
atat=tat/n;
printf("\navg waiting time is :%f",awt);
printf("\navg turn around time is :%f",atat);

return 0;
}