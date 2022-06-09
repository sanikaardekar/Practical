#include<stdio.h>
#define V 7
#define MAX 10000
int graph[][V] ={
        {0,6,5,5,0,0,0},
        {0,0,0,0,-1,0,0},
        {0,-2,0,0,1,0,0},
        {0,0,-2,0,0,-1,0},
        {0,0,0,0,0,0,3},
        {0,0,0,0,0,0,3},
        {0,0,0,0,0,0,0}
};
int main(){
int d[V],prnt[V];
for(int i=0;i<V;i++){
d[i]=MAX;
prnt[i]=-1;
}
d[0]=0;
for(int i=0;i<V-1;i++)
{
for(int j=0;j<V;j++){
for(int k=0;k<V;k++){
if(graph[j][k]+d[j]<d[k] && graph[j][k]!=0){
d[k]=graph[j][k]+d[j];
prnt[k]=j;
}
}
}
} 
printf("node dist parent\n");
//negative cycle
for(int i=0;i<V;i++){
for(int j=0;j<V;j++){
if(graph[i][j]+d[i]<d[j]){
for(int k=0;k<V;k++){
printf("%d %d %d\n",k+1,d[k],prnt[k]);
}
printf("graph contains neg cycle");
return 0;
}
}
}
for(int i=0;i<V;i++){
printf("%d %d %d\n",i+1,d[i],prnt[i]);
}
return 0; 
}