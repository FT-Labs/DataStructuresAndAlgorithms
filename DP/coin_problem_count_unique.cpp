#include <iostream>
#include <cstring>
using namespace std;


//This problem is called UNBOUNDED KNAPSACK.

/*
	if at c[m-1] , take as many instances of coin. count(c, m, n-c[m-1]) then move to [m-2].
*/


int solve(int c[], int m, int n)
{
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;
	//If there are no coins and n>0, no solution
	if(m<=0 && n>0)
		return 0;

	return solve(c, m-1, n)+solve(c, m, n-c[m-1]);
}


//Below is the bottom down dp approach, which doesnt calculate all recursive calls. It is much faster. O(m*n)

int solveDP(int c[], int m, int n)
{
	int dp[n+1][m];

	//Fill all entries for 0 to 1.
	for(int i=0; i<m; i++)
		dp[0][i] = 1;

	int x, y;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i-c[j] >= 0)
				x = dp[i - c[j]][j];
			else
				x = 0;

			if(j>=1)
				y = dp[i][j-1];
			else
				y = 0;

			dp[i][j] = x+y;
		}
	}

	return dp[n][m-1];
}


//Below is simplified version which uses a 1d array.
int solveDP1D(int c[], int m, int n)
{
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i=0; i<m; i++)
	{
		//Pick coins one by one and update values of dp[] after the index is greater than or equal to value of picked coin.
		for(int j=c[i]; j<=n; j++)
			dp[j] += dp[j-c[i]];
	}

	return dp[n];
}

int main()
{
	int arr[] = {4, 5, 8};
	int m = sizeof(arr)/sizeof(arr[0]);
	int n = 14;
	cout << solve(arr, m, n) << endl;
	cout << solveDP(arr, m, n) << endl;
	cout << solveDP1D(arr, m, n) << endl;

	return 0;
}
