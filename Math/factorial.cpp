#include <iostream>
#include <time.h>
using namespace std;

#define mod 1000000009

//Recursive version of factorial finding algorithm

long long facRec(long long n)
{
	if(n == 1)
		return 1;
	return ( (n%mod) * (facRec(n-1)%mod) % mod );
}

//Iterative version
long long factIt(long long n)
{
	long long res = 1;

	for(long long i=1; i <= n ; ++i)
		res = (res*i)%mod;

	return res;
}


int main()
{
	long long n;
	cin >> n;
	//Calc clock
	clock_t tStart = clock();

	long long res = factIt(n);

	cout.precision(6);

	cout << "Time taken is:" << fixed << (double) (clock() - tStart)/CLOCKS_PER_SEC << endl;
	cout << res << endl;

	return 0;

}
