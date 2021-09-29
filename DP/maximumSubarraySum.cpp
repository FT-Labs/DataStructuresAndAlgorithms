#include <iostream>
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;


//Naive solution: 2 loops, O(n^2)
int maximumSubarraySum(int arr[], int n)
{
	int mx = 0;

	for(int i=0; i<n; i++)
	{
		int sum = 0;
		for(int j=0; j<=i; j++)
		{
			sum += arr[j];
			mx = max(mx, sum);
		}
	}
	return mx;
}

//Good solution: Divide array from middle, like merge sort. Calculate left sum of left half and right half, then return maximum.
// O(n*logn)
int maxCrossingSum(int arr[], int l, int m, int r)
{
	int sum = 0;
	int leftSum = 0;
	for(int i=m; i>=l; i--)
	{
		sum += arr[i];
		leftSum = max(leftSum, sum);
	}

	sum = 0;
	int rightSum = 0;
	for(int i=m+1; i<=r; i++)
	{
		sum += arr[i];
		rightSum = max(rightSum, sum);
	}

	//Note that this fails on [-2, 1]
	return max(rightSum+leftSum, max(leftSum, rightSum));
}


int maximumSubarraySum(int arr[], int l, int r)
{
	if(l>=r)
		return arr[l];

	//Get middle
	int m = l+(r-l)/2;

	/* Return maximum of three possible cases:
		i) max sum in left half
		ii) max sum in right half
		iii) max sum that crosses middle */

	return max(maximumSubarraySum(arr, l, m), max(maximumSubarraySum(arr, m+1, r), maxCrossingSum(arr, l, m, r)));
}



int main()
{
	int arr[] = {2, -1, 2, 3, 4, -5};
	int n = SIZE(arr);

	cout << maximumSubarraySum(arr, n) << endl;
	cout << maximumSubarraySum(arr, 0, n-1) << endl;



	return 0;
}
