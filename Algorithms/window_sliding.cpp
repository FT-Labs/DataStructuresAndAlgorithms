#include <iostream>
using namespace std;


// Time Complexity : O(n)
int windowSlide(int arr[], int n, int k)
{
	int currentWindow = 0;

	for (int i=0; i<k; i++)
		currentWindow += arr[i];

	int maxWindow = currentWindow;

	for (int i=k; i<n; i++)
	{
		currentWindow += arr[i] - arr[i-k];
		maxWindow = max(currentWindow, maxWindow);
	}

	return maxWindow;
}


int main()
{
	int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
	int k = 4, n = sizeof(arr)/sizeof(arr[0]);

	cout << windowSlide(arr, n, k) << endl;

	return 0;
}
