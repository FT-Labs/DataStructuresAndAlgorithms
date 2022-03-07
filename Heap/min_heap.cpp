#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	std::priority_queue<int, vector<int>, greater<int> > pq;

	pq.push(5);
	pq.push(1);
	pq.push(10);
	pq.push(15);
	pq.push(23);



	while(!pq.empty())
	{
		cout << pq.top() << ' ';
		pq.pop();
	}


	return 0;
}
