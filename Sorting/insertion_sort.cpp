#include <iostream>
#include <vector>
using namespace std;


void insertionSort(int arr[], int n)
{
	int key,j;
	for(int i=1;i<n;++i)
	{
		key = arr[i];
		j = i-1;

		while(j>=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}


// Cool insertion sort with swapping, but a little bit slower
void insertionSortC(int arr[], int n)
{
	for (int i=1; i<n; i++)
		for (int j=i; j>0 && arr[j] < arr[j-1]; j--)
			swap(arr[j], arr[j-1]);
}


int main()
{
	int arr[] = {1,4,3,5,6,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSortC(arr,n);

	for(int i=0;i<n;++i)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
