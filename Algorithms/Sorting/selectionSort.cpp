#include <iostream>
using namespace std;


void selectionSort(int arr[],int n)
{

	for(int i=0;i<n-1;++i)
	{
		int swp = i;
		for(int j=i+1;j<n;++j)
		{
			if(arr[j]<arr[swp])
				swp = j;
		}
		swap(arr[i],arr[swp]);
	}

}

void selectionSortRecursive(int arr[],int n,int start=0)
{
	if(start == n-1)
		return;

	int swp = start;
	for(int i=start+1;i<n;++i)
	{
		if(arr[i]<arr[swp])
			swp = i;
	}
	swap(arr[start],arr[swp]);

	selectionSortRecursive(arr,n,start+1);
}


int main()
{
	int arr[] = {1,3,6,4,5,9,11,7,12};
	int n = sizeof(arr)/sizeof(arr[0]);

	selectionSortRecursive(arr,n);

	for(int i=0;i<n;++i)
		cout << arr[i] << ' ';

	cout << endl;

	return 0;
}
