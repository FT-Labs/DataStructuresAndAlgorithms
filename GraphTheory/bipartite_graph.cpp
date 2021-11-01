#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;


bool isBipartite(vector<vector<int>>& v, int src)
{
	// use color array to store colors assigned to all vertices.
	// -1 is used to state that there is currently no color on edge.
	// 1 is first color, 0 is second color
	int colorArr[v[0].size()];
	memset(colorArr, -1, sizeof(colorArr));
	colorArr[src] = 1;

	//creating queue for BFS traversal
	queue<int> q; q.push(src);

	while (!q.empty())
	{
		int u = q.front(); q.pop();

		//return false if it is a self loop
		if (v[u][u] == 1)
			return false;

		for (int i=0; i<v[0].size(); i++)
		{
			// u->v exists and v is not colored
			if (v[u][i] && colorArr[i] == -1)
			{
				colorArr[i] = 1 - colorArr[u];
				q.push(i);
			}
			else if (v[u][i] && colorArr[i] == colorArr[u])
				return false;
		}
	}

	return true;
}


int main()
{
	vector<vector<int>> v = {{0, 1, 0, 1},
							 {1, 0, 1, 0},
							 {0, 1, 0, 1},
							 {1, 0, 1, 0}};


	cout << isBipartite(v, 0) << endl;

	return 0;
}
