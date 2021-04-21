#include <iostream>
#include <time.h>
using namespace std;

#define mod 1000000007

long long fastExp(long long n, long long k)
{
	if(k == 0) return 1;
	if(k == 1) return n;

	long long temp = fastExp(n, k>>1);

	//If k is odd return n*temp*temp
	//If k is even return temp*temp
	//Take mod since it can overflow

	if((k&1) == 1) return (n*temp*temp) % mod;
	return (temp*temp) %mod;
}

int main()
{
	long long k,n;
	scanf("%lld%lld", &n, &k);

	clock_t tStart = clock();

	long long res = fastExp(n,k);
	cout.precision(6);

	cout << "Time taken:" << fixed << (double) (clock()-tStart)/CLOCKS_PER_SEC;
	cout << endl << res;

	return 0;

}

