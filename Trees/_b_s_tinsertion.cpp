#include <iostream>
using namespace std;

class Node
{
	public:
	int key;
	Node* left,*right;
};

Node* newNode(int item)
{
	Node* tmp = new Node();
	tmp->key = item;
	tmp->left = tmp->right = NULL;
	return tmp;
}

void inOrder(Node* root)
{
	if(root == NULL)
		return;

	inOrder(root->left);
	cout << root->key << ' ';
	inOrder(root->right);

}

Node* insert(Node* node,int key)
{
	if(node == NULL)
		return newNode(key);

	//Recur down the tree
	if(key<node->key)
		node->left = insert(node->left,key);
	else if(key>node->key)
		node->right = insert(node->right,key);

	return node;
}


int main()
{
	Node* root = NULL;
	root = insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);

	inOrder(root);

	return 0;
}

