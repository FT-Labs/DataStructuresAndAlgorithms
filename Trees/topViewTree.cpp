#include <queue>
#include <iostream>
#include <map>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;

		Node()
		{
			left = NULL;
			right = NULL;
		}
};

map<int,Node*> topView(Node* root)
{
	queue<pair<int,Node*>> q;
	q.push(make_pair(0,root));

	map<int,Node*> ans;

	for(auto i=q.front();!q.empty();q.pop(),i=q.front())
	{
		if(!i.second)
			continue;

		ans.insert(i);

		q.push(make_pair(i.first+1,root->right));
		q.push(make_pair(i.first-1,root->left));
	}

	return ans;
}
