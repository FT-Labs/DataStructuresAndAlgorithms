#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getMaxArea(vector<int> hist)
{
	//Stack holds indexes of hist array. Bars stored in stack is always
	//in increasing heights.
	stack<int> s;

	int maxArea = 0;
	int tp; //Top of stack
	int areaWithTop; //Store the area with top bar as smallest one


	int i = 0;
	while (i<hist.size())
	{
		//If bar is higher than the bar on top, push it in stack
		if(s.empty() || hist[s.top()] <= hist[i])
				s.push(i++);

		//If bar is lower than top of stack, calculate the area of rectangle with stack
		//top as smallest (min height) bar
		// 'i' is right index for top and element before top in stack if left index
		else
		{
			tp = s.top();
			s.pop();

			//Calculate area with hist[tp] as smallest bar
			areaWithTop = hist[tp] * (s.empty() ? i : i-s.top()-1);

			//Update max area if needed

			if(maxArea < areaWithTop)
				maxArea = areaWithTop;
		}
	}

	//Pop remaining bars and calculate area withe very popped bar as smallest one

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




int main()
{
	vector<int> hist = {6, 2, 5, 4, 5, 1, 6};
	cout << "Max area is: " << getMaxArea(hist) << endl;
	return 0;
}
