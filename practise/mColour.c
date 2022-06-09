#include<stdio.h>
int n,m;
int g[50][50];
int x[50];
void nextValue(int k){
int i;
x[k]=(x[k]+1)%(m+1);
if(x[k]==0)
return;
for(i=0;i<n;i++){
if(g[k][i]!=0 && x[k]==x[i]){
break;
}
}
if(i==n){
return;
}
else{
nextValue(k);
}
}
void mColouring(int k){
nextValue(k);
if(x[k]==0)
{ return;
}
if(k==n-1){
printf("solution is: ");
for(int i=0;i<n;i++){
printf("%d",x[i]);
}
}
else{
mColouring(k+1);
}
}

int main(){
int edge;
printf("enter number of colours\n");
scanf("%d",&m);
printf("enter number of nodes\n");
scanf("%d",&n);
printf("enter number of edges\n");
scanf("%d",&edge);

for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
g[i][j]=0;
}
x[i]=0;
}
int k,l;
printf("enter edge of vertices\n");
for(int i=0;i<edge;i++){
scanf("%d %d",&k,&l);
g[k][l]=1;
g[l][k]=1;
}
mColouring(0);
return 0;
}