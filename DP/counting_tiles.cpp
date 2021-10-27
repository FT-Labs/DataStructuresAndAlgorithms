#include <iostream>
using namespace std;


//Way to count number of different ways. Note that parts need to be 1xm for this to work as well as nxm table.
//Simple dp solution.
int solve(int n, int m)
{
	int count[n+1];
	count[0] = 0;

	for(int i=1; i<=n; i++)
	{
		if(i > m)
			count[i] = count[i-1] + count[i-m];
		else if(i<m || i==1)
			count[i] = 1;
		else
			count[i] = 2;
	}

	return count[n];
}

//Recursive approach of above solution.
int count[100]{0};
int solveRecursive(int n, int m)
{
	if(n < m || n == 1)
		return 1;
	if(n == m)
		return 2;
	if(count[n] != 0)
		return count[n];

	count[n] = solveRecursive(n-1, m) + solveRecursive(n-m, m);

	return count[n];
}

//Below solution is for when table is nx3, and m is 2x1 tiles.
int solve(int n)
{
	int A[n+1];
	A[0] = 1, A[1] = 0;
	int B[n+1];
	B[0] = 0, B[1] = 1;

	for(int i=2; i<=n; i++)
	{
		A[i] = A[i-2] + 2*B[i-1];
		B[i] = A[i-1] + B[i-2];
	}


	return A[n];
}



int main()
{
	int n = 7, m = 4;
	count[0] = 0;


	cout << solve(n, m) << endl;
	cout << solveRecursive(n, m) << endl;


	return 0;
}
