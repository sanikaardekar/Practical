#include <stdio.h>
int main()
{
int n1=7;
int i, h[n1];
printf("enter bits for hamming code generation\n");
for(i=1;i<=7;i++)
{
scanf("%d",&h[i]);
}
printf("\n");
int arr[3];
int p1=h[1]+h[3]+h[5]+h[7];
int p2=h[2]+h[3]+h[6]+h[7];
int p3=h[4]+h[6]+h[5]+h[7];
if(p1%2==0)
{
printf("no error in p1\n");
arr[3]=0;
}
else{
printf("error in p1\n");
arr[3]=1;
}
if(p2%2==0)
{
printf("no error in p2\n");
arr[2]=0;
}
else{
printf("error in p2\n");
arr[2]=1;
}
if(p3%2==0)
{
printf("no error in p3\n");
arr[1]=0;
}
else{
printf("error in p3\n");
arr[1]=1;
}
for(i=1;i<=3;i++)
{
printf("\n%d",arr[i]);
}
int k=0;
for(i=1;i<=3;i++)
{
k=k*10+arr[i];
}
int dec_num=0,base=1,rem;
while(k>0){
rem=k%10;
dec_num=dec_num+rem*base;
k=k/10;
base=base*2;
}
if(h[dec_num]==1)
{
h[dec_num]=0;
}
else{
h[dec_num]=1;
}
printf("correct hamming code is\n");
for(i=1;i<=n1;i++)
{
printf("%d",h[i]);
}
return 0;
}