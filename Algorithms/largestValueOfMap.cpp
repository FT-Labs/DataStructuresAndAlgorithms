#include <map>
#include <iostream>
using namespace std;

pair<int,int> largestValue(map<int,int> mp)
{
	//Reference variable to swap it
	pair<int,int> maxVal = make_pair(0,0);

	//Iterate through map to find the entry
	map<int,int>::iterator cur;

	for(cur = mp.begin();cur != mp.end(); ++cur)
	{
		//If entries value is more than max set it to max

		if(cur->second > maxVal.second)
		{
			maxVal = make_pair(cur->first,cur->second);
		}
	}
	return maxVal;
}
