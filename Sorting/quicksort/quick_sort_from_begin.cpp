#include <iostream>
using namespace std;

#define SIZE(x) sizeof(x)/sizeof(x[0])


int partition(int arr[], int l, int r)
{
	int i = r, j;
	int piv = arr[l];

	for (int j=r; j>l; j--)
	{
		if (arr[j] > piv)
		{
			swap(arr[j], arr[i]);
			i--;
		}
	}

	swap(arr[i], arr[l]);
	return i;
}

void quickSort(int arr[], int l, int r)
{
	if (l>=r) return;

	int piv = partition(arr, l, r);
	quickSort(arr, l, piv);
	quickSort(arr, piv+1, r);
}


int main()
{
	int arr[] = {1, 3, 2, 8, 11, 19, 13};
	int n = SIZE(arr);

	quickSort(arr, 0, n-1);

	for (auto it : arr)
		cout << it << ' ';

	return 0;
}
