#include <stdio.h>
void division(int dividend[],int coeff[],int n1,int n,int rem[])
{
int i,j, temp;
for(i=0;i<n1;i++)
{
temp=i;
if(dividend[i]==1)
{
for(j=0;j<n;j++)
{
if(dividend[temp]==coeff[j])
{
dividend[temp] =0;
rem[j]=0;
}
else{
dividend[temp] =1;
rem[j]=1;
}
temp++;
}
}
}
printf("remainder is:\n");
for(i=0;i<n;i++)
{
printf("%d",rem[i]);
}
}
int main()
{
int coeff[50], rem[50], data[50];
int n, n1;
printf("enter number of coeff bits\n");
scanf("%d",&n);
printf("enter coeff bits\n");
for(int i=0;i<n;i++)
{
scanf("%d",&coeff[i]);
}
printf("\nenter number of data bits");
scanf("%d",&n1);
printf("enter data bits\n");
for(int i=0;i<n1;i++)
{
scanf("%d",&data[i]);
}
int dividend[n1+n-1];
for(int i=0;i<(n1+n-1);i++){
dividend[i]=data[i];
if(i>=n1)
{
dividend[i]=0;
}
}
rem[n]; int dup[n1+n-1];
for(int i=0;i<(n1+n-1);i++){
dup[i]=dividend[i];
}
division(dividend,coeff,n1,n,rem);
if(rem[0]==0)
{
for(int i=0;i<(n1+n-1);i++)
{
dup[n1+i]=rem[i+1];
}
}
for(int i=0;i<(n1+n-1);i++)
{
printf("%d",dividend[i]);
}
for(int i=0;i<(n1+n-1);i++)
{
printf("%d",dup[i]);
}
division(dup,coeff,n1,n,rem);
return 0;
}