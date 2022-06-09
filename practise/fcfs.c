#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("enter number of requests\n");
scanf("%d",&n);
int req[n],sum=0,cur,diff;
printf("enter requests\n");
for(int i=0;i<n;i++)
scanf("%d",&req[i]);
printf("enter current head position\n");
scanf("%d",&cur);
sum=sum+abs(req[0]-cur);
for(int i=0;i<n-1;i++){
diff=abs(req[i]-req[i+1]);
sum=sum+diff;
}
printf("total head mvt is= %d",sum);
return 0;
}