#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("enter number of requests\n");
scanf("%d",&n);
int req[n]; int thm=0; int count=0; int initial;
printf("enter requests\n");
for(int i=0;i<n;i++){
scanf("%d",&req[i]);
}
printf("enter initial head");
scanf("%d",&initial);
while(count!=n){
int min=1000,d,index;
for(int i=0;i<n;i++){
d=abs(req[i]-initial);
if(min>d){
min=d;
index=i;
}
}
thm=thm+min;
initial=req[index];
req[index]=1000;
count++;
}
printf("\ntotal head movement is= %d",thm);

return 0;
}