#include <iostream>
using namespace std;


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];

	int j, i = low - 1;

	for (j = low; j < high; j++) {
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[++i], arr[high]);
	return i;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int piv = partition(arr, low, high);

		quickSort(arr, low, piv - 1);
		quickSort(arr, piv, high);
	}
}

int main()
{
	int arr[] = {1, 3, 2, 8, 11, 14, 18};
	int n = sizeof(arr) / sizeof(arr[0]);

	for (auto it : arr) cout << it << ' ';
	cout << endl;

	quickSort(arr, 0, n-1);

	for (auto it : arr) cout << it << ' ';
	cout << endl;

	return 0;
}
