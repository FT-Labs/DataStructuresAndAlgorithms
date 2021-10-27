#include <queue>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;



int main()
{
	srand(time(NULL));

	priority_queue<int> pq;

	for(int i=0;i<10;i++)
	{
		int rnd = rand()%100;
		pq.push(rnd);
	}


	while(!pq.empty())
	{
		cout << pq.top() << ' ';
		pq.pop();
	}

	return 0;
}
