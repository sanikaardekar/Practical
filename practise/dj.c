#include <stdio.h>
#define V 9
#define MAX 100
int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
int min(int d[V],int vis[V]){
int dmin=MAX, min_index;
for(int i=0;i<V;i++){
if(dmin>=d[i] && vis[i]!=1){
dmin=d[i];
min_index=i;
}
}
return min_index;
}
int main(){
int prnt[V], d[V], vis[V];
for(int i=0;i<V;i++){
d[i]=MAX;
prnt[i]=-1;
vis[i]=0;
}
d[0]=0;
for(int i=0;i<V;i++)
{
int j=min(d,vis);
vis[j]=1;
for(int k=0;k<V;k++){
if(vis[k]!=1 && graph[j][k]+d[j]<d[k] && graph[j][k]!=0)
{
d[k]=d[j]+graph[j][k];
prnt[k]=j;
}
}
}
int sum=0;
printf("node	distance	parent\n");
for(int i=0;i<V;i++){
printf("%d	%d	%d\n",i,d[i],prnt[i]);
sum=sum+d[i];
}
printf("sum= %d",sum);
 
return 0;
}