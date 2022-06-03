#include<stdio.h> 
#include<time.h>
#include<stdlib.h>

int n;

void swap(int *c,int *d)
{
    int t = *c;
    *c = *d;
    *d = t;
}

int partition(int a[],int s,int e)
{
    int pivot = a[s];
    int start = s;
    int end = e;
    while(start<end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[s],&a[end]);
    return end;
}

void quicksort(int a[],int s,int e)
{
    if(s<e)
    {
        int loc = partition(a,s,e);
        quicksort(a,s,loc-1);
        quicksort(a,loc+1,e);
    }
}


int main() 
{ 
    int n=11; 
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10}; 
    clock_t begin = clock();
    quicksort(arr,0,10);
    clock_t end = clock();
    printf("Time taken for array of 10 = %ld",end-begin);

    int r = 100;
    int arr2[r];
    for(int i=0;i<r;i++){
        arr2[i] = rand();
    }
    // printf("Hello");
    // for(int i=0;i<50;i++){
    //     printf("%d",arr2[i]);
    // }
    printf("\n");
    clock_t s = clock();
    quicksort(arr2,0,r);
    clock_t e = clock()-s;
    float x=((double)e);
    printf("Time taken for sorting array of %d %f ",r,x);
    
    // int r = 50000;
    int arr3[r];
    int z = 0;
    for(int i=0;i<r;i++){
        arr3[i] = z;
        z++;
    }

    printf("\n");
    clock_t s1 = clock();
    quicksort(arr3,0,r);
    clock_t e1 = clock()-s1;
    float x1=((double)e1);
    printf("Time taken for sorting array of %d in ascending order %f ",r,x1);
    

    int arr4[r];
    int t = r;
    for(int i=0;i<r;i++){
        arr4[i] = t;
        t--;
    }

    printf("\n");
    clock_t s2 = clock();
    quicksort(arr4,0,r);
    clock_t e2 = clock()-s2;
    float x2=((double)e2);
    printf("Time taken for sorting array of %d in descending order %f ",r,x2);


    return  0; 
} 