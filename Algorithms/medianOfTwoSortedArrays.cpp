#include <iostream>
#include <vector>
using namespace std;


//A little bit of bad algorithm. O(sizeof(A)+sizeof(B)). Can be reduced to O(min(log(A),log(B)))

double getMedian(vector<int> A,vector<int> B)
{
	int n = A.size();
	int m = B.size();
	int i = 0; //index for vec A
	int j = 0; //index for vec B
	int m1 = -1, m2 = -1;
	bool flag = false;


	//If median is just one element
	if ((n+m)%2==1)
		flag = true;

	for(int count=0;count<=(n+m)/2;count++)
	{
		m2 = m1;
		if (i!=n && j!=m)
			m1 = (A[i]>B[j]) ? B[j++] : A[i++];
		else if(i<n)
			m1 = A[i++];
		else
			m1 = B[j++];
	}
	return (flag ? m1 : (double)(m1+m2)/2.0f);
}


int main()
{
	vector<int> A = {1,4,5};
	vector<int> B = {2,3};
	cout << getMedian(A,B) << endl;
	return 0;
}
