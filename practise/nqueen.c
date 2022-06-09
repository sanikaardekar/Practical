#include<stdio.h>
#include<stdlib.h>
int z=4;
int a[4];
int Place(int k,int i){
for(int j=0;j<k;j++){
if(a[j]==i || abs(a[j]-i)==abs(j-k))
{
return 0;
}
}
return 1;
}
void Nqueen(int k,int n){
for(int i=0;i<n;i++){
if(Place(k,i)==1){
a[k]=i;
if(k==n-1){
for(int m=0;m<n;m++){
printf("%d",a[m]);
}
printf("\n");
}
else{
Nqueen(k+1,n);
}
}
}
}

int main(){
Nqueen(0,z);
return 0;
}