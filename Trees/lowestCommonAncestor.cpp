#include <bits/stdc++.h>

using namespace std;


class Node
{
	public:
	int data;
	Node* left,*right;
};

//Assume both n1 and n2 in tree

Node* lca(Node* root,int n1,int n2)
{
	if(root == NULL)
		return NULL;

	//If both n1 and n2 are smaller than root, then they're at
	//left subtree

	if(root->data > n1 && root->data > n2)
		return lca(root->left,n1,n2);

	//If both n1 and n2 are greater than root, then they're at
	//right subtree

	if(root->data < n1 && root->data < n2)
		return lca(root->right,n1,n2);

	return root;
}

Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

int main()
{
	Node* root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	int n1 = 10, n2 = 14;
	cout << "LCA OF:" << n1 << ' ' << n2 << endl;
	Node* t = lca(root,10,14);
	cout << t->data << endl;

	return 0;
}

