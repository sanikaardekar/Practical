#include<stdio.h>
#include<math.h>
#include<string.h>

void rabin(char txt[100], char ptn[100], int d, int q){
int i; int h=1;
int hashT=0,hashP=0;
int n=strlen(txt);
int m=strlen(ptn);
h=( int )(pow(d,m-1))%q;
for(i=0;i<m;i++){
hashT=(hashT*d+txt[i])%q;
hashP=(hashP*d+ptn[i])%q;
}
for(int s=0;s<=n-m;s++){
if(hashP==hashT){

for(i=0;i<m;i++){
if(ptn[i]!=txt[s+i]){
break;
}
}
if(i==m){
printf("pattern appears at: %d",s-1);
}
}
if(s<n-m){
hashT=(d*(hashT-(txt[s]*h))+txt[s+m])%q;
if(hashT<0)
hashT=hashT+q;
}
}
}

int main(){
char ptn[100], txt[100];
printf("enter text: ");
scanf("%s",txt);
printf("enter pattern to be searched: ");
scanf("%s",ptn);
int d=256;
int q=31;
rabin(txt,ptn,d,q);
return 0; 
}