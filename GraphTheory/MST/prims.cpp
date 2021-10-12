#include <bits/stdc++.h>
using namespace std;

// Define no of vertices
#define V 5

// Prims algorithm for MST

// A utility function to find vertex with minimum key val, from set of vertices not included in MST
int minKey(int key[], bool mstSet[])
{
	//Define min as infinite
	int mn = INT_MAX, min_index;

	for(int v=0; v<V; v++)
		if(mstSet[v] == false && key[v] < mn)
			mn = key[v], min_index = v;

	return min_index;
}

//Print minimum spanning tree
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight" << endl;
	for(int i=1; i<V; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
}


//Construct MST with a graph using adjacency matrix
// Time Complexity : O(V^2)
void primMST(int graph[V][V])
{
	// Array to store MST
	int parent[V];

	//Key to pick minimum weight edge
	int key[V];

	//Represent used vertices in MST
	bool mstSet[V];

	//Initialize all keys as infinite
	for(int i=0; i<V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	//Always include first vertex in MST. Make key 0 so it is chosen first
	key[0] = 0;
	parent[0] = -1; //First node is always root of mst

	for(int cnt=0; cnt<V-1; cnt++)
	{
		int u = minKey(key, mstSet);

		mstSet[u] = true;

		//Update key value and parent index of adjacent vertices of picked vertex. Use only not used vertices
		for(int v=0; v<V; v++)
		{
			if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
		}
	}

	//Print MST
	printMST(parent, graph);
}


int main()
{
	//Adjacency matrix of a graph
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);

	return 0;
}
