#include <iostream>
using namespace std;

struct Tree
{
	int value;
	Tree* left;
	Tree* right;

	Tree(int value):value(value)
	{
		this->left = nullptr;
		this->right = nullptr;
	}
};


int kthSmallest(Tree* root, int& k)
{
	if(!root)
		return 0;

	//Start inorder traversal
	int left = kthSmallest(root->left,k);
	if(left)
		return left;
	--k;
	//If k is zero return value
	if(!k)
		return root->value;

	int right = kthSmallest(root->right,k);
	return right;
}
