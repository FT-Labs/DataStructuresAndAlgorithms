#include <iostream>
#include <algorithm>
#define size(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;


// This is a classical dp question. Implementation below takes O(n^2) time.
// However there is a better solution with O(n*logn) time. If you cant find that in this repo, check geeks for geeks.

int LIS(int arr[], int size)
{
	//Note that mx is needed to store maximum value.
	//This is not like a knapsack problem, maximum value can be anywhere in array.
	int mx = 0;
	int dp[size];

	for(int i=0; i<size; i++)
	{
		dp[i] = 1;
		for(int j=0; j<i; j++)
		{
			if(arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j]+1);
				mx = max(mx, dp[i]);
			}
		}
	}

	return mx;
}


//Note that this solution is slower because it doesnt use memoization. There are some sites made this with memoization, just use a for loop for this one because its much more easier.
int LISRecursive(int arr[], int i, int n, int prev)
{
	if (i == n)
		return 0;

	// exclude the current element and process the remaining elements
	int exclude = LISRecursive(arr, i + 1, n, prev);

	// include the current element if it is greater than previous element in LIS
	int include = 0;
	if (arr[i] > prev)
		include = 1 + LISRecursive(arr, i + 1, n, arr[i]);

	return max(include, exclude);
}



int main()
{
	int arr[] = {6, 2, 5, 1};

	cout << LIS(arr, size(arr)) << endl;
	cout << LISRecursive(arr, 0, size(arr), 0) << endl;

	return 0;
}
