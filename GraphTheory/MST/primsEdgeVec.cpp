#include <bits/stdc++.h>
using namespace std;


struct Edge
{
	int n1, n2, w;

	Edge(int n1, int n2, int w):n1(n1), n2(n2), w(w)
	{}
};


bool cmp(Edge& e1, Edge& e2)
{
	return e1.w < e2.w;
}

int find(vector<int>& d, int a)
{
	//If edge is unused, return current edge
	if(d[a] == -1)
		return a;

	return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b)
{
	a = find(d, a);
	b = find(d, b);

	// Check if it is equal to itself
	if(a == b)
		return;

	d[a] = b;
}

int main()
{
	vector<Edge> v;

	int edges = 5;
	v.push_back(Edge(0, 1, 2));
	v.push_back(Edge(0, 3, 6));
	v.push_back(Edge(1, 0, 2));
	v.push_back(Edge(1, 2, 3));
	v.push_back(Edge(1, 3, 8));
	v.push_back(Edge(1, 4, 5));
	v.push_back(Edge(2, 1, 3));
	v.push_back(Edge(2, 4, 7));
	v.push_back(Edge(3, 0, 6));
	v.push_back(Edge(3, 1, 8));
	v.push_back(Edge(3, 4, 9));
	v.push_back(Edge(4, 1, 5));
	v.push_back(Edge(4, 2, 7));
	v.push_back(Edge(4, 3, 9));

	sort(v.begin(), v.end(), cmp);

	int w = 0;
	vector<int> d(edges, -1);

	for(auto& edge : v)
	{
		if(find(d, edge.n1) != find(d, edge.n2))
		{
			join(d, edge.n1, edge.n2);
			w += edge.w;
		}
	}


	cout << "Cost of min spanning tree is:" << endl << w << endl;



	return 0;
}
