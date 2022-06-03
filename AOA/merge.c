/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


/* Driver code */
int main()
{
    
    int n=11; 
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10}; 
    clock_t begin = clock();
    mergeSort(arr,0,10-1);
    clock_t end = clock();
    printf("Time taken for array of 10 = %ld",end-begin);
    
    int r=10000;

    int arr2[r];
    for(int i=0;i<r;i++){
        arr2[i] = rand();
    }
    
    printf("\n");
    clock_t s = clock();
    mergeSort(arr2, 0, r - 1);
    clock_t e = clock()-s;
    float x=((double)e);
    printf("Time taken for sorting array of %d %f ",r,x);
    
    int arr3[r];
    int z = 0;
    for(int i=0;i<r;i++){
        arr3[i] = z;
        z++;
    }

    printf("\n");
    clock_t s1 = clock();
    mergeSort(arr3, 0, r - 1);
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
    mergeSort(arr4, 0, r - 1);
    clock_t e2 = clock()-s2;
    float x2=((double)e2);
    printf("Time taken for sorting array of %d in descending order %f ",r,x2);
    
	return 0;
}
