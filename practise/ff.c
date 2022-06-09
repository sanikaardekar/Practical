#include<stdio.h>
int main(){
int n,m;
printf("enter number of slots\n");
scanf("%d",&n);
int slots[n];
for(int i=0;i<n;i++){
printf("\nenter slot ");
scanf("%d",&slots[i]);
}
printf("\nenter number of processes\n");
scanf("%d",&m);
int process[m];
for(int i=0;i<m;i++){
printf("\nenter process ");
scanf("%d",&process[i]);
}

for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
if(process[i]<=slots[j]){
printf("%d->%d\n",process[i],slots[j]);
slots[j]=slots[j]-process[i];
break;
}
}
}
for(int i=0;i<n;i++)
printf("\nslots after first fit %d",slots[i]);
return 0;
}