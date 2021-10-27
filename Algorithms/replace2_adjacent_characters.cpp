#include <iostream>
#include <set>
using namespace std;


//This is a dynamic programming question.


//Question is : only 3 characters in string (a, b, c). Given this string, you can replace 2 adjacent characters to other one. Find minimum size of this string by replacing elements.

int solve(string s)
{
	set<char> se;
	int arr[3]{0};

	for(auto ch : s)
	{
		se.insert(ch);
		arr[ch-'a']++;
	}


	//If sets size is one, return size of string since nothing is changeable

	if(se.size() == 1)
	{
		return s.size();
	}
	else
	{
		//Other condition is easy. If all characters are even or odd, answer will be 1. Otherwise it will be 2.

		bool odd = false, even = false;

		for(int i=0; i<3; i++)
		{
			if((arr[i]&1))
				odd = true;
			else
				even = true;
		}

		return ((odd && even) ? 1 : 2);
	}
}


int main()
{
	string s = "bcab";
	string s1 = "bbaacc";

	cout << solve(s) << endl;
	cout << solve(s1) << endl;



	return 0;
}
