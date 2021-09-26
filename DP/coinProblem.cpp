#include <iostream>
#include <cmath>
#define size(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

/*

   Note that this problem is really similar to knapsack problems. The difference is in knapsack problems you can only use each element once.
   In coin change problem, you can use each coin infinitely.
*/


int solve(int arr[], int size, int sum)
{
	int dp[sum+1];
	dp[0] = 0;

	for(int i=1; i<=sum; i++)
	{
		dp[i] = 1e8;
		for(int j=1; j<size; j++)
		{
			if(i-arr[j] >= 0)
				dp[i] = min(dp[i], dp[i - arr[j]]+1);
		}
	}
	return dp[sum];
}

int dp[1000]{0};


//Recursive approach of same question, note that you need to declare dp array globally
int solveRecursive(int arr[], int size, int sum)
{
	if(sum<0)
		return 1e8;
	if(sum == 0)
		return 0;
	if(dp[sum] != 0)
		return dp[sum];

	int best = 1e8;

	for(int i=0; i<size; i++)
		best = min(best, solveRecursive(arr, size, sum - arr[i])+1);

	dp[sum] = best;
	return best;
}



int main()
{
	// Problem is to find minimum number of coins to achieve given sum.

	int coins[] = {1, 3, 4};
	int sum = 38;

	cout << solve(coins, size(coins), sum) << endl;
	cout << solveRecursive(coins,  size(coins), sum) << endl;


	return 0;
}
