#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

vector <pair<int, pair<int, int> > > edges;
int parent[MAX], rnk[MAX];

int find_set(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}

bool union_set(int x, int y){
    int i = find_set(x),
        j = find_set(y);

    if(i != j)
	{
        if(rnk[i] > rnk[j])
            parent[j] = i;
        else
            parent[i] = j;

        return true;
    }
    return false;
}

int kruskal(int v, int e){
    int mst = 0, k = 0, w, x, y;

    sort(edges.begin(), edges.end());

    for(int i = 0; i < e && k < v - 1; i++){
        w = edges[i].first;
        x = edges[i].second.first, y = edges[i].second.second;

        if(union_set(x, y)){
            mst += w;
            k++;
        }
    }

    return mst;
}

int main(){

    int v, e, x, y, w;
	cin >> v >> e;

    for(int i = 1; i <= v; i++){
        rnk[i] = 0;
        parent[i] = i;
    }

    for(int i=0; i<e; i++){
        scanf("%d %d %d", &x, &y, &w);
        edges.push_back(make_pair(w, make_pair(x, y)));
    }

    cout << kruskal(v, e);

    return 0;
}
