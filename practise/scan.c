#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("enter number of requests\n");
scanf("%d",&n);
int req[n],initial,size,move,thm=0;
printf("enter requests\n");
for(int i=0;i<n;i++)
scanf("%d",&req[i]);
printf("enter iniatial head\n");
scanf("%d",&initial);
printf("enter move, 1 for high and 0 for low\n");
scanf("%d",&move);
printf("enter size of disk\n");
scanf("%d",&size);
int index,temp;
for(int i=0;i<n;i++)
{
for(int j=0;j<n-i-1;j++){
if(req[j]>req[j+1]){
temp=req[j];
req[j]=req[j+1];
req[j+1]=temp;
}
}
}
for(int i=0;i<n;i++){
if(req[i]>initial)
{
index=i;
break;
}
}

if(move==1){
int i;
for(i=index;i<n;i++){
thm=thm+abs(req[i]-initial);
initial=req[i];
}
thm=thm+abs(size-req[i-1]-1);
initial=size-1;
for(i=index-1;i>=0;i--){
thm=thm+abs(req[i]-initial);
initial=req[i];
}
}
else if(move==0){
int i;
for(i=index-1;i>=0;i--){
thm=thm+abs(req[i]-initial);
initial=req[i];
}
thm=thm+abs(req[i+1]-0);
initial=0;
for(i=index;i<n;i++){
thm=thm+abs(req[i]-initial);
initial=req[i];
}
}
printf("total head movement is= %d",thm);
return 0;
}