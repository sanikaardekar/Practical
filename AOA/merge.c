#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int num = 50000;
    int arr[num], r;
    srand(time(NULL));
    for (int i = 0; i < num; i++)
    {
        r = rand() % num;
        arr[i] = r;
    }

    // avg case
    clock_t begin1 = clock();
    mergeSort(arr, 0, num - 1);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

    printf("Average Case (Random Order): Time taken by Merge Sort:%f \n", time_spent1);


    begin1 = clock();
    mergeSort(arr, 0, num - 1);
    end1 = clock();
    time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

    printf("Sorted Array Case (Increasing Order): Time taken by Merge Sort:%f \n", time_spent1);

    int temp, j = num - 1;
    for (int i = 0; i < num / 2; i++)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j = j - 1;
    }

    clock_t begin2 = clock();
    mergeSort(arr, 0, num - 1);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

    printf("Sorted Array Case (Decresing Order): Time taken by Merge Sort:%f \n", time_spent2);
    return 0;
} 
