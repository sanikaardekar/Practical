#include<stdio.h>

int main(){
int nop,at[10],bt[10],sum=0,count=0, wt, tat, y, temp[10], quant;
float awt,att;
printf("enter no of preocesses\n");
scanf("%d",&nop);
y=nop;
for(int i=0;i<nop;i++){
printf("enter arrival time for process");
scanf("%d",&at[i]);
printf("\nenter burst time for process");
scanf("%d",&bt[i]);
temp[i]=bt[i];
}
printf("\nenter time interval");
scanf("%d",&quant);

for(int i=0;y!=0;){
if(temp[i]<=quant && temp[i]>0){
sum=sum+temp[i];
temp[i]=0;
count=1;
}
else if(temp[i]>0){
sum=sum+quant;
temp[i]=temp[i]-quant;
}
if(temp[i]==0 && count==1){
y--; 
printf("\nprocess %d turnaround time %d waiting time %d",(i+1),sum-at[i],sum-at[i]-bt[i]);
tat=tat+sum-at[i];
wt=wt+sum-at[i]-bt[i]; 
}
if(i==nop-1){
i=0;
}
else if(at[i-1]<=sum){
i++;
}
else{
i=0;
}
}
awt=wt*1.0/nop;
att=tat*1.0/nop;
printf("\navg waiting time %f\n",awt);
printf("\navg turnaround time %f\n",att);
return 0;
}