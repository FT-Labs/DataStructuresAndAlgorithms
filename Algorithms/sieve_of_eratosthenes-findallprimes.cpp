#include <bits/stdc++.h>
using namespace std;


void sieveOfErastosthenes(int n)
{
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	//If prime[p] is not changed, it is a prime
	for(int i=2;i*i<=n;++i)
	{
		//Update all multiples of p greater than or equal to square of it
		for(int j=i*i;j<=n;j+=i)
		{
			prime[j] = false;
		}
	}

	//Print all prime numbers
	for(int i=2;i<=n;++i)
	{
		if(prime[i])
			cout << i << ' ';
	}
	cout << endl;
}

int main()
{
	int n=100;
	cout << "Prime numbers < than:" << n << endl;
	sieveOfErastosthenes(n);
	return 0;
}
