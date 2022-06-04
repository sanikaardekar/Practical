#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void selectionsort(int arr[], int n)
{
    int i, min, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int num = 50000;
    int r, arr[num], arr2[num];
    srand(time(NULL));
    for (int i = 0; i < num; i++)
    {
        r = rand() % num;
        arr[i] = r;
    }
    for (int i = 0; i < num; i++)
    {
        arr2[i] = arr[i];
    }

    // avg case
    clock_t begin1 = clock();
    selectionsort(arr, num);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    clock_t begin2 = clock();
    insertionSort(arr2, num);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("Average Case: Time taken by Insertion Sort:%f \n\tTime taken by Selection Sort:%f ", time_spent2, time_spent1);

    // best case
    begin1 = clock();
    selectionsort(arr, num);
    end1 = clock();
    time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    begin2 = clock();
    insertionSort(arr2, num);
    end2 = clock();
    time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("\nBest Case: Time taken by Insertion Sort:%f \n\tTime taken by Selection Sort:%f ", time_spent2, time_spent1);

    // worst case here
    int temp, j = num - 1;
    for (int i = 0; i < num / 2; i++)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;

        temp = arr2[j];
        arr2[j] = arr2[i];
        arr2[i] = temp;
        j = j - 1;
    }
    begin1 = clock();
    selectionsort(arr, num);
    end1 = clock();
    time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    begin2 = clock();
    insertionSort(arr2, num);
    end2 = clock();
    time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("\nWorst Case: Time taken by Insertion Sort:%f \n\tTime taken by Selection Sort:%f ", time_spent2, time_spent1);

    return 0;
}