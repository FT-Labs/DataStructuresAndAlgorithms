#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int checkRecursive(int x,int n, int curr_num = 1, int curr_sum = 0)
{
	//Initialize number of ways to express x
	//as nth power of natural numbers
	int res = 0;

	//Calling power of 'i' to 'n'
	int p = pow(curr_num,n);


	while(p+curr_sum < x)
	{
		//Recursively check all greater values of i
		res += checkRecursive(x,n,curr_num+1,p+curr_sum);

		++curr_num;
		p = pow(curr_num,n);
	}

	//If sum of powers is equal to x then increase value of result
	if(p+curr_sum == x)
		++res;

	return res;
}


int main()
{
	int x,n;
	cin >> x >> n;
	cout << checkRecursive(x,n);


	return 0;
}




