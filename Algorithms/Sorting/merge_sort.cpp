#include <iostream>
#include <vector>
#define forn(x,j) for(int i=x;i<j;i++)
using namespace std;

// O(nlogn)


void merge(int arr[],int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;

	//Temp arrays
	int L[n1],R[n2];

	//Copying the data
	for(int i=0;i<n1;i++)
		L[i] = arr[l+i];
	for(int j=0;j<n2;j++)
		R[j] = arr[m+1+j];

	//Merging arrays
	int i = 0;
	int j = 0;

	//Initial index of merged subarray
	int k = l;

	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l,int r)
{
	if(l>=r)
		return;
	int m = l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

int main()
{
	int arr[] = {1,5,2,3,6,8,12,11};
	int n = sizeof(arr)/sizeof(arr[0]);

	forn(0,n)
		cout << arr[i] << ' ';

	cout << endl;

	mergeSort(arr,0,n-1);

	forn(0,n)
		cout << arr[i] << ' ';



	return 0;
}
