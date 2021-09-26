#include <iostream>
#include <algorithm>
#define size(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;


// This is nearly the same as coin problem. Only difference is you have to calculate total number of solutions instead of minimum number of coins.


int solve(int coins[], int size, int sum)
{
	int dp[sum+1];
	fill(dp, dp+sum+1, 0);
	dp[0] = 1;


	for(int i=1; i<=sum; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(i - coins[j] >= 0)
				dp[i] += dp[i-coins[j]];
		}
	}
	return dp[sum];
}


int dp[100]{0};
int solveRecursive(int coins[], int size, int sum)
{
	if(sum < 0)
		return 0;
	if(sum == 0)
		return 1;
	if(dp[sum] != 0)
		return dp[sum];

	for(int i=0; i<size; i++)
		dp[sum] += solveRecursive(coins, size, sum-coins[i]);
	return dp[sum];
}



int main()
{
	int coins[] = {1, 3, 4};
	int sum = 10;

	cout << solve(coins, size(coins), sum) << endl;
	cout << solveRecursive(coins, size(coins), sum) << endl;



	return 0;
}
