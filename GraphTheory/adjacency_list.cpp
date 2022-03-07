#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#define mp make_pair
using namespace std;

int main()
{
	int vertices, edges, v1, v2, weight;

	printf("Enter number of vertices: \n");
	scanf("%d", &vertices);

	printf("Enter the number of edges: \n");
	scanf("%d", &edges);

	//Adjacency list is a vector of list
	//Each element is a pair<int,int>
	//pair.first -> destination
	//pair.second -> edges weight
	vector<list<pair<int, int>>> adjacencyList(vertices+1);


	printf("Enter edges V1 -> V2, weight: n\n");

	for(int i=0;i<edges;i++)
	{
		scanf("%d%d%d", &v1, &v2, &weight);

		//Add edge to directed graph
		adjacencyList[v1].push_back(mp(v2, weight));
	}

	printf("Adjacency list: \n");

	for(int i=0;i<adjacencyList.size();i++)
	{
		printf("adjacencyList[%d]", i);

		list<pair<int,int>>::iterator it = adjacencyList[i].begin();

		while (it != adjacencyList[i].end())
		{
			printf(" -> %d(%d)", (*it).first, (*it).second);
			++it;
		}
		cout << endl;
	}
	return 0;
}
