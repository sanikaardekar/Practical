#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("enter number of req\n");
scanf("%d",&n);
int req[n],cur,dir,arrup[n],arrdown[n],l=0,k=0,thm=0;
printf("enter the requests\n");
for(int i=0;i<n;i++)
scanf("%d",&req[i]);
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(req[i]>req[j]){
int temp=req[i];
req[i]=req[j];
req[j]=temp;
}
}
}
printf("enter initial head\n");
scanf("%d",&cur);
for(int i=0;i<n;i++){
if(req[i]>cur)
{
arrup[k]=req[i];
k++;
}
else if(req[i]<cur)
{
arrdown[l]=req[i];
l++;
}
}
printf("enter direction 0 for low, 1 for up\n");
scanf("%d",&dir);
if(dir==1){
thm=abs(cur-arrup[k-1]);
thm=thm+abs(arrdown[0]-arrup[k-1]);
}
else if(dir==0){
thm=abs(cur-arrdown[0]);
thm=thm+abs(arrdown[0]-arrup[k-1]);
}
else{
printf("enter correct direction\n");
}
printf("total head mvt= %d",thm);

return 0;
}