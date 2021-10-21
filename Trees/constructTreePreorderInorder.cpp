#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
	int value;
	Node* right, *left;

	Node(int value):value(value)
	{}
};



struct Node* buildTree(int in[],int pre[],int inStart,int inEnd,unordered_map<int,int>& mp)
{
	static int preIndex = 0;

	if(inStart > inEnd)
		return nullptr;

	// Pick current node from preorder using preindex and increment
	int cur = pre[preIndex++];
	struct Node* tNode = new Node(cur);

	//If this node has no child return
	if (inStart == inEnd)
		return tNode;

	int inIndex = mp[cur];

	//Using index in inorder traversal, construct left and right trees
	tNode->left = buildTree(in, pre, inStart, inIndex-1, mp);
	tNode->right = buildTree(in, pre, inIndex+1, inEnd, mp);

	return tNode;
}

//This function builds unordered_map then calls buildTree()
struct Node* makeMapFromTree(int in[],int pre[], int len)
{
	unordered_map<int,int> mp;
	for(int i=0;i<len;i++)
	{
		mp[in[i]] = i;
	}
	return buildTree(in, pre, 0, len-1, mp);
}


void printInorder(struct Node* root)
{
	if(root == nullptr)
		return;

	printInorder(root->left);

	cout << root->value << ' ';

	printInorder(root->right);
}


int main()
{
	int in[] = {4, 2, 1, 5, 3, 6};
	int pre[] = {1, 2, 4, 3, 5 , 6};

	struct Node* root = makeMapFromTree(in, pre, sizeof(in)/sizeof(in[0]));

	printInorder(root);

	return 0;
}
