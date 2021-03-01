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


int main()
{
	int arr[] = {1,4,3,5,6,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSort(arr,n);

	for(int i=0;i<n;++i)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
