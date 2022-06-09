#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m,n;
void Print_lcs(int b[m][n], char x[100], int i, int j){
if(i==0 || j==0){
return;
}
if(b[i][j]==0){
Print_lcs(b,x,i-1,j-1);
printf("%c",x[i-1]);
}
else if(b[i][j]==1){
Print_lcs(b,x,i-1,j);
}
else{
Print_lcs(b,x,i,j-1);
}
}
int main(){
char s1[100],s2[100];
printf("enter 1st string ");
scanf("%s",s1);
printf("enter 2nd string ");
scanf("%s",s2);
m=strlen(s1);
n=strlen(s2);
int b[m][n]; int c[m+1][n+1];
for(int i=0;i<=m;i++){
c[i][0]=0;
}
for(int j=0;j<=n;j++){
c[0][j]=0;
}

for(int i=1;i<=m;i++){
for(int j=1;j<=n;j++){
if(s1[i-1]==s2[j-1]){ //impp
c[i][j]=c[i-1][j-1]+1;
b[i][j]=0;
}
else if(c[i-1][j]>c[i][j-1]){
c[i][j]=c[i-1][j];
b[i][j]=1;
}
else{
c[i][j]=c[i][j-1];
b[i][j]=2;
}
}
}
Print_lcs(b,s1,m,n);
return 0;
}