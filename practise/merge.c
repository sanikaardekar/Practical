#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int l1[n1], l2[n2];
    for (int i = 0; i < n1; i++)
    {
        l1[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        l2[j] = arr[m + 1 + j];
    }
    int k = 1, i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (l1[i] <= l2[j])
        {
            arr[k] = l1[i];
            i++;
        }
        else
        {
            arr[k] = l2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = l1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = l2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - 1) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int num = 50000;
    srand(time(NULL));
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        int r = rand() % num;
        arr[i] = r;
    }
    clock_t begin = clock();
    mergeSort(arr, 0, num - 1);
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("avg case= %f\n", time);

    begin = clock();
    mergeSort(arr, 0, num - 1);
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
    mergeSort(arr, 0, num - 1);
    end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("worst case= %f\n", time);
    return 0;
}