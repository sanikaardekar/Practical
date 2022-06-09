#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
int t=*a;
*a=*b;
*b=t;
}

int partition(int arr[],int low,int high){
int pivot =arr[high];
int i=low-1;

for(int j=low;j<high;j++){
if(arr[j]<pivot){
i++;
swap(&arr[i],&arr[j]);
}
}
swap(&arr[i+1],&arr[high]);
return (i+1);
}

void quick(int arr[],int low, int high){
if(low<high){
int p = partition(arr,low,high);
quick(arr,low,p-1);
quick(arr,p+1,high);
}
}

int main(){
int num = 50000;
    srand(time(NULL));
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        int r = rand() % num;
        arr[i] = r;
    }
    clock_t begin = clock();
    quick(arr, 0, num - 1);
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("avg case= %f\n", time);

    begin = clock();
    quick(arr, 0, num - 1);
    end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("best case= %f\n", time);

    int temp, j = num - 1;
    for (int i = 0; i < num / 2; i++)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j--;
    }
    begin = clock();
    quick(arr, 0, num - 1);
    end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("worst case= %f\n", time);
return 0;
}