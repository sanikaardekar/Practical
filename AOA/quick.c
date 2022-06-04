#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high)
{

    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
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
    //  printf("\nArray-\n");
    //  for(int i=0;i<num;i++){
    //  printf("%d ",arr[i]);
    //  }
    clock_t begin1 = clock();
    quickSort(arr, 0, num - 1);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

    printf("\nAverage Case (Random Order): Time taken by Quick Sort:%f \n", time_spent1);

    // Best case

    begin1 = clock();
    quickSort(arr, 0, num - 1);
    end1 = clock();
    time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

    printf("\nSorted Array Case (Increasing Order):: Time taken by Quick Sort:%f \n", time_spent1);

    // Worst Case
    int temp, j = num - 1;
    for (int i = 0; i < num / 2; i++)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j = j - 1;
    }

    clock_t begin2 = clock();
    quickSort(arr, 0, num - 1);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

    printf("\nSorted Array Case (Decresing Order):: Time taken by Quick Sort:%f \n", time_spent2);
    return 0;
}

