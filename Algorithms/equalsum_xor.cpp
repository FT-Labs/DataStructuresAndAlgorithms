#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	int cnt = 0;

	while(n)
	{
		if((n&1) == 0)
			++cnt;
		n >>= 1;
	}

	cout << (1<<cnt) << endl;

	return 0;
}
