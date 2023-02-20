#include <stdio.h>
#define LENGTH(x) sizeof(x)/sizeof(x[0])

void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void sel_sort(int arr[], int n)
{
	int i, j, min_idx = 0;

	for (i = 0; i < n - 1; i++, min_idx = i) {
		for (j = i + 1; j < n;  min_idx = arr[j] < arr[min_idx] ? j : min_idx, j++);
		if (min_idx != i) swap(&arr[min_idx], &arr[i]);
	}
}


int main ()
{
	int arr[] = {1, 198, 22, 8, 192,4, 3, 2, 12, 9, 11, 19};

	for (size_t i = 0; i < LENGTH(arr); i++) {
		printf("%d ", arr[i]);
	}
	puts("\n");

	sel_sort(arr, LENGTH(arr));

	for (size_t i = 0; i < LENGTH(arr); i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}
