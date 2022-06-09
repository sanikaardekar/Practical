#include<stdio.h>
int w[]={2,3,4,5};
int m=7;
int x[4];
int count=1;

void subset(int s,int k,int r){
int n=sizeof(w)/sizeof(w[0]); 
x[k]=1;
if(s+w[k]==m){
printf("soln %d",count);
count++;
for(int i=0;i<n;i++){
printf("%d ",x[i]);
}
printf("\n");
for(int i=0;i<n;i++){
x[i]=0;
}
}
else if(s+w[k]+w[k+1]<=m && k!=n-1){
subset(s+w[k],k+1,r-w[k]);
}
if(s+r-w[k]>=m && k!=n-1 && s+w[k+1]<=m){
x[k]=0;
subset(s,k+1,r-w[k]);
}
}
int main(){
int sum=0;
for(int i=0;i<(sizeof(w)/sizeof(w[0]));i++)
sum=sum+w[i];
subset(0,0,sum);
return 0;
}