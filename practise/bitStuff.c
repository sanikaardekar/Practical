#include <stdio.h>
int main(){
int n, a[20], b[30];
printf("enter number of bits\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("enter data bits: ");
scanf("%d",&a[i]);
}
int i=0,j=0,k, count=1;
while(i<n){
if(a[i]==1){
b[j]=a[i];
for(k=i+1;k<n && count<5 && a[k]==1;k++){
j++;
b[j]=a[k];
count++;
if(count==5){
j++;
b[j]=0;
}
i=k;
}
}
else{
b[j]=a[i];
}
i++; j++;
}
printf("after bit stuffing: ");
for(i=0;i<j;i++)
printf("%d",b[i]);
return 0;
}