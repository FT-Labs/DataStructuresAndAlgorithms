#include <bits/stdc++.h>
using namespace std;

//Function to sort vector elements by the second element of pairs
// i.e to configure them by looking at their right ends

bool sortbysec(const pair<int,int>& a,const pair<int,int>& b)
{
	return (a.second < b.second);
}

void maxDisjointIntervals(vector<pair<int, int> > vec)
{
	//Sort them first
	sort(vec.begin(),vec.end(),sortbysec);

	//First interval will be always included in the set

	cout << '[' << vec[0].first << ',' << vec[0].second << ']' << endl;

	//End point of first interval
	int r1 = vec[0].second;

	for(int i=1;i<vec.size();++i)
	{
		int f1 = vec[i].first;
		int f2 = vec[i].second;


		//Check if given interval overlap with previously included
		//interval, if not then include this interval and
		//update the end point of last added interval
		if(f1>r1)
		{
			cout << '[' << f1 << ',' << f2 << ']' << endl;
			r1 = f2;
		}
	}
}


int main()
{
	vector<pair<int ,int> > intervals = { {1, 4},
										  {2, 3 },
										  {4, 6},
										  {8, 9}};

	maxDisjointIntervals(intervals);

	return 0;
}
