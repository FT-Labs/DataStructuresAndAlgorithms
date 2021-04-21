#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxHist(vector<int> hist)
{
	stack<int> s;
	int maxArea = 0;
	int areaWithTop;
	int tp;

	int i = 0;
	while(i<hist.size())
	{
		if(s.empty() || hist[i]>=hist[s.top()])
			s.push(i++);
		else
		{
			tp = s.top();
			s.pop();
			areaWithTop = hist[tp] * (s.empty() ? i : i-s.top()-1);

			if(maxArea < areaWithTop)
				maxArea = areaWithTop;
		}
	}

	while(!s.empty())
	{
		tp = s.top();
		s.pop();
		areaWithTop = hist[tp] * (s.empty() ? i : i-s.top()-1);

		if(maxArea < areaWithTop)
			maxArea = areaWithTop;
	}

	return maxArea;
}


int maxSize(vector<vector<int>> mat)
{
	int maxArea = 0;
	vector<int> hist(mat.size(),0);

	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j] == 0)
				hist[j] = 0;
			else
				hist[j]++;
		}
		maxArea = max(maxArea,maxHist(hist));
	}

	return maxArea;
}




int main()
{
	vector<vector<int>> mat = {{1,1,1,0,1,1},
								{1,1,0,0,0,1},
								{1,1,1,0,0,1},
								{0,1,1,0,0,1}};
vector<vector<int>> mat1 = {
{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
{  1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{  0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1} ,
{  1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1} ,
{  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
{  1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1} ,
{  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0} ,
{  1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1} ,
{  1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1} ,
{  1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
{  1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
{  1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1} ,
{  1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1} ,
{  1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1} ,
};
	cout << "Maximum area rectangle is:" << maxSize(mat) << endl;

	return 0;
}
