#include<stdio.h>
int main(){
int n,m;
printf("enter slots\n");
scanf("%d",&n);
int slots[n]; 
for(int i=0;i<n;i++){
printf("\n enter slot");
scanf("%d",&slots[i]);
}
printf("enter process\n");
scanf("%d",&m);
int process[m]; int all[m];
for(int i=0;i<m;i++){
printf("\n enter process");
scanf("%d",&process[i]);
all[i]=-1;
}
for(int i=0;i<m;i++){
int worstplace=-1;
for(int j=0;j<n;j++){
if(slots[j]>=process[i]){
if(worstplace==-1)
{
worstplace=j;
}
else if(slots[worstplace]<slots[j])
{
worstplace=j;
}
}
}
if(worstplace!=-1){
all[i]=worstplace;
slots[worstplace]=slots[worstplace]-process[i];
}
}
printf("process id\tprocess\tblock number\n");
for(int i=0;i<m;i++){
printf("%d\t\t%d\t\t",(i+1),process[i]);
if(all[i]!=-1){
printf("%d\n",all[i]+1);
}
else
{
printf("not allocated\n");
}
}
for(int i=0;i<=m;i++){
        printf("%d ",slots[i]);
    }

return 0;
}