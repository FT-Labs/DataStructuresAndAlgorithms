#include <bits/stdc++.h>
using namespace std;

//Inorder (Left,Root,Right)
//Preorder (Root,Left,Right)
//Postorder (Left,Right,Root)


class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};


void printPostOrder(Node* node)
{
	if(node == NULL)
		return;

	//First recur on left subtree
	printPostOrder(node->left);

	//Then to right subtree
	printPostOrder(node->right);

	//Then node
	cout << node->data << " ";
}

void printInorder(Node* node)
{
	if(node == NULL)
		return;

	printInorder(node->left);

	cout << node->data << ' ';

	printInorder(node->right);
}


void printPreorder(Node* node)
{
	if(node == NULL)
		return;

	cout << node->data << ' ';

	printPreorder(node->left);

	printPreorder(node->right);

}


int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	//Preorder
	printPreorder(root);
	//Inorder
	cout << endl;
	printInorder(root);
	//Post order
	cout << endl;
	printPostOrder(root);


	return 0;
}
