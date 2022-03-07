#include <iostream>
using namespace std;

int partition(int arr[], int left, int right, int piv)
{
	while (left <= right)
	{
		while (arr[left] < piv) left++;
		while (arr[right] > piv) right--;

		if (left <= right)
		{
			swap(arr[left], arr[right]);
			left++, right--;
		}
	}
	return left;
}

void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int piv = (left + right) / 2;
		int idx = partition(arr, left, right, arr[piv]);

		quickSort(arr, left, idx-1);
		quickSort(arr, idx, right);
	}
}

int main()
{
	int arr[] = {3, 2, 6, 4, 11, 8, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	for (auto it : arr) cout << it << ' ';
	cout << endl;

	quickSort(arr, 0, n - 1);

	for (auto it : arr) cout << it << ' ';
	cout << endl;

	return 0;
}
