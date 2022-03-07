#include <iostream>
#include <cstring>
#include <numeric>
#define size(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;


//The problem here is to calculate all possible sums of an array by using each element once.
//value[i][j] holds if the sum is constructable or not.
int knapSack(int arr[], int size, int sum)
{
	bool value[size+1][sum+1];
	for(int i=0; i<=size; i++)
	{
		for(int j=0; j<=sum; j++)
			value[i][j] = false;
	}

	value[0][0] = true;

	for(int i=1; i<=size; i++)
	{
		for(int j=0; j<=sum; j++)
		{
			if(j-arr[i-1] >= 0)
				value[i][j] |= value[i-1][j-arr[i-1]];
			value[i][j] |= value[i-1][j];
		}
	}

	for(int i=0; i<=size; i++)
	{
		for(int j=0; j<=sum; j++)
			cout << value[i][j] << ' ';
		cout << endl;
	}


	return accumulate(value[size],value[size]+sum+1, 0)-1;
}



int main()
{
	int arr[] = {1, 3, 3, 5};
	int size = size(arr);
	int tot = 0;
	tot = accumulate(arr, arr+size, 0);

	cout << knapSack(arr, size, tot) << endl;

	return 0;
}
