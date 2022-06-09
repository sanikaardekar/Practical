#include<stdio.h>
#define n 9
int prnt[n]; int rank[n];
int minans[2]={-1,-1};
int G[][n]={        
    {0,4,0,0,0,0,0,0,8},
    {4,0,8,0,0,0,0,0,11},
    {0,8,0,7,0,4,0,2,0},
    {0,0,7,0,9,14,0,0,0},
    {0,0,0,9,0,10,0,0,0},
    {0,0,10,14,4,0,2,0,0},
    {0,0,0,0,0,2,0,6,1},
    {0,0,2,0,0,0,6,0,7},
    {8,11,0,0,0,0,1,7,0}
};
int find(int x){
if(prnt[x]!=x){
prnt[x]=find(prnt[x]);
}
return prnt[x];
}
void unioN(int x, int y){
int xroot = find(x);
int yroot=find(y);
if(xroot==yroot){
return;
}
if(rank[xroot]<rank[yroot]){
prnt[xroot]=yroot;
}
else if(rank[yroot]<rank[xroot]){
prnt[yroot]=xroot;
}
else {
prnt[xroot]=yroot;
rank[yroot]=rank[yroot]+1;
}
}

int min(){
int minm=100;
for(int i=0;i<n;i++){
for(int j=i;j<n;j++){
if(minm>G[i][j] && G[i][j]!=0){
minm=G[i][j];
minans[0]=i;
minans[1]=j;
}
}
}
return minm;
}

void kruskal(){
int soli[n-1],solj[n-1];
int cost=0;
int count=0;
while(min()<100){
int i=find(minans[0]);
int j=find(minans[1]);
if(i!=j){
cost=cost+G[minans[0]][minans[1]];
unioN(minans[0],minans[1]);
soli[count]=minans[0],solj[count]=minans[1];
count++;
}
G[minans[0]][minans[1]]=0;
G[minans[1]][minans[0]]=0;
}
for(int i=0;i<count;i++){//impp o to count for display
printf("(%d,%d)",soli[i],solj[i]);
}
printf("total cost: %d",cost);
}

int main(){
for(int i=0;i<n;i++){
prnt[i]=i;
rank[i]=0;
}
kruskal();
return 0;
}