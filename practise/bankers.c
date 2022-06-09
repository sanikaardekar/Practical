#include<stdio.h>
int main(){
int n=5,m=3;
int alloc[5][3] = { { 0, 1, 0 }, 
						{ 2, 0, 0 }, 
						{ 3, 0, 2 },
						{ 2, 1, 1 }, 
						{ 0, 0, 2 } }; 

int max[5][3] = { { 7, 5, 3 },
					{ 3, 2, 2 }, 
					{ 9, 0, 2 }, 
					{ 2, 2, 2 }, 
					{ 4, 3, 3 } };
int avail[3] = { 3, 3, 2 };
int f[n],ans[n],ind=0,flag; int need[n][m];
for(int i=0;i<n;i++){
f[i]=0;
}
for(int i=0;i<n;i++){
for(int j=0;j<m;i++){
need[i][j]=max[i][j]-alloc[i][j];
}
}
int y;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(f[j]==0){
flag=0;
for(int k=0;k<m;k++){
if(need[j][k]>avail[k]){
flag=1;
break;
}
}
if(flag==0){
ans[ind++]=j;
for(y=0;y<m;y++){
avail[y]=avail[y]+alloc[j][y];
}
f[j]=1;
}
}
}
}
flag=1;
for(int i=0;i<n;i++){
if(f[i]==0)
{
flag=0;
printf("not safe");
break;
}
}
if(flag==1){
printf("safe seq\n");
for(int i=0;i<n-1;i++){
printf("P%d ->",ans[i]);
}
printf("P%d",ans[n-1]);
}
return 0;
}