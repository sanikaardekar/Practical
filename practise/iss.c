#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion(int arr[],int n){
int i,j,key;
for(i=1;i<n;i++){
key=arr[i];
j=i-1;
while(j>=0 && arr[j]>key){
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
}
void selection(int arr[], int n){
int i,min,j,temp;
for(i=0;i<n-1;i++){
min=i;
for(j=i+1;j<n;j++){
if(arr[j]<arr[min]){
min=j;
}
}
temp=arr[min];
arr[min]=arr[i];
arr[i]=temp;
}
}
int main(){
int num=50000;
srand(time(NULL));
int arr[num],arr2[num];
for(int i=0;i<num;i++){
int r=rand()%num;
arr[i]=r;
}
for(int i=0;i<num;i++){
arr2[i]=arr[i];
}
//avg case
clock_t begin1=clock();
insertion(arr,num);
clock_t end1=clock();
double time_taken1=(double)(end1-begin1)/CLOCKS_PER_SEC;
printf("avg case for insertion=%f\n",time_taken1);
clock_t begin2=clock();
selection(arr2,num);
clock_t end2=clock();
double time_taken2=(double)(end2-begin2)/CLOCKS_PER_SEC;
printf("avg case for selection=%f\n",time_taken2);

//best case
begin1=clock();
insertion(arr,num);
end1=clock();
time_taken1=(double)(end1-begin1)/CLOCKS_PER_SEC;
printf("best case for insertion=%f\n",time_taken1);
begin2=clock();
selection(arr2,num);
end2=clock();
time_taken2=(double)(end2-begin2)/CLOCKS_PER_SEC;
printf("best case for selection=%f\n",time_taken2);

//worst case
int temp,j=num-1;
for(int i=0;i<num/2;i++){
temp=arr[j];
arr[j]=arr[i];
arr[i]=temp;

temp=arr2[j];
arr2[j]=arr2[i];
arr2[i]=temp;

j--;
}
begin1=clock();
insertion(arr,num);
end1=clock();
time_taken1=(double)(end1-begin1)/CLOCKS_PER_SEC;
printf("worst case for insertion=%f\n",time_taken1);
begin2=clock();
selection(arr2,num);
end2=clock();
time_taken2=(double)(end2-begin2)/CLOCKS_PER_SEC;
printf("worst case for selection=%f\n",time_taken2);

return 0;
}