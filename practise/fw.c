#include<stdio.h>
#define MAX 999
int min(int a, int b){
if(a<b){
return a;
}
return b;
}
void floyd(int w[100][100],int n){
int d[100][100];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
d[i][j]=w[i][j];
}
}
for(int k=0;k<n;k++){
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
d[i][j]=min(d[i][j],(d[i][k]+d[k][j]));
}
}
}
printf("solution\n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(d[i][j]==MAX){
printf("%7s","INF");
}
else{
printf("%7d",d[i][j]);
}
}
printf("\n");
}
}
int main(){
int n;
printf("enter number of nodes\n");
scanf("%d",&n);
printf("enter adjacancy matrix\n");
int d[100][100];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
int temp;
scanf("%i",&temp);
if(temp!=MAX){
d[i][j]=temp;
}
else{
d[i][j]=MAX;
}
}
}
floyd(d,n);
return 0;
}