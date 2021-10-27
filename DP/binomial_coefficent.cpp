#include <iostream>
using namespace std;

int binomialCoefficient(int n, int k)
{
	int C[n+1][k+1];


	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(n,k);j++)
		{
			//Base cases
			if (j==0 || j==i || i==0)
				C[i][j] = 1;
			else
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	return C[n][k];
}


int main()
{
	int n = 5,k = 5;
	cout << "Value of C[" << n << "][" << k << "] is " << binomialCoefficient(n,k) << endl;

	return 0;
}
