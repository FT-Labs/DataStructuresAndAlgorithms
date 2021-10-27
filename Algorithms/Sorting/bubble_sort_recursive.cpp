#include <iostream>
using namespace std;


void bubblesort(int arr[],int n)
{
	if(n == 1)
		return;

	for(int i=0;i<n-1;++i)
	{
		if(arr[i]>arr[i+1])
			swap(arr[i],arr[i+1]);
	}

	bubblesort(arr,n-1);
}


int main()
{
	int arr[] = {1,3,4,8,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,n);

	for(int i=0;i<n;++i)
		cout << arr[i] << ' ';

	cout << endl;

	return 0;

}
