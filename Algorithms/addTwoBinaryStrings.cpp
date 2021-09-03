#include <iostream>
using namespace std;


string addBinary(string a, string b)
{
	string ans = "";
	int s = 0;

	//Traverse both strings from last char
	int i = a.size()-1, j = b.size()-1;

	while(i>=0 || j>= 0 || s == 1)
	{
		s += ((i>=0) ? a[i]-'0' : 0);
		s += ((j>=0) ? b[j]-'0' : 0);

		//if current digit sum is 1 or 3, add 1 to ans
		ans = char(s%2 + '0') + ans;
		s /= 2;

		i--; j--;
	}

	return ans;
}
