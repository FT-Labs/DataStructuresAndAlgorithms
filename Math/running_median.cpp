#include <bits/stdc++.h>
using namespace std;


// Insertion sort also works on this algorithm, however has a time complexity of O(n**2). Using heaps will reduce this time complexity. STL Priority queue is going to be used.


void getMedians(double arr[], int n)
{
	// max heap to store smaller half elements
	priority_queue<double> maxHeapSmaller;

	//min heap to store greater half elements
	priority_queue<double, vector<double>, greater<double>> minHeapGreater;

	double med = arr[0]; //Get the first median
	maxHeapSmaller.push(arr[0]);

	cout << med << endl;

	/*
	   At any time heaps need to be balanced. Therefore their sizes must be differ by maximum of 1.
	   If heaps are balanced, declare median as average of minHeapRight.top() and maxHeapLeft.top().
	   If they are unbalanced, then  the median is defined as top element of heap with larger size. */

	for(int i=1; i<n; i++)
	{
		double cur = arr[i];

		// Case 1: maxHeap has more elements
		if(maxHeapSmaller.size() > minHeapGreater.size())
		{
			if(cur < med)
			{
				minHeapGreater.push(maxHeapSmaller.top());
				maxHeapSmaller.pop();
				maxHeapSmaller.push(cur);
			}
			else
				minHeapGreater.push(cur);

			med = (minHeapGreater.top() + maxHeapSmaller.top())/2.0;
		}
		else if(minHeapGreater.size() == maxHeapSmaller.size())
		{
			if(cur < med)
			{
				maxHeapSmaller.push(cur);
				med = (double) maxHeapSmaller.top();
			}
			else
			{
				minHeapGreater.push(cur);
				med = (double) minHeapGreater.top();
			}
		}
		else //Last case: Greater half elements has more size than smaller elements
		{
			if(cur > med)
			{
				maxHeapSmaller.push(minHeapGreater.top());
				minHeapGreater.pop();
				minHeapGreater.push(cur);
			}
			else
			{
				maxHeapSmaller.push(cur);
			}

			med = (maxHeapSmaller.top() + minHeapGreater.top())/2.0;
		}

		cout << med <<  endl;
	}
}


int main()
{
	double arr[] = {5, 15, 10, 20, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	getMedians(arr, n);

	return 0;
}
