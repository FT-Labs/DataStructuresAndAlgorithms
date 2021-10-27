#include <iostream>
#include <vector>
using namespace std;

#define NO_OF_CHARS 256


int longestUniqueSubsttr(string s)
{
	int n = s.size();

	int res = 0;

	// Last index of all chars -> initialize as
	vector<int> lastIndex(NO_OF_CHARS, -1);

	for(int i=0, j=0; j<n; j++)
	{
		//Find last index of s[j]
		//Update i as max of current value of i and lastIndex + 1

		i = max(i, lastIndex[s[j]]+ 1);

		//Update res
		res = max(res, j-i+1);

		//Update last index of j
		lastIndex[s[j]] = j;

	}
	return res;
}


int main()
{
	string s = "HelloWorld";

	cout << "Length of longest non repeating character is: " << longestUniqueSubsttr(s) << endl;



	return 0;
}
