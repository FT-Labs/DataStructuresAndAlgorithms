#include <bits/stdc++.h>
using namespace std;


class Node
{
	public:
		int data;
		Node* left,*right;
		Node(int n):data(n)
		{
			left = NULL;
			right = NULL;
		}
};

//Functions
void printGivenLevel(Node* root,int level);
int height(Node* node);
Node* newNode(int data);

//Function to print the level order traversal of a tree

void printLevelOrder(Node* root)
{
	int h = height(root);

	for(int i=1;i<=h;++i)
	{
		printGivenLevel(root,i);
	}
}

//Print nodes at a given level

void printGivenLevel(Node* root,int level)
{
	if(root == NULL)
		return;
	if(level == 1)
		cout << root->data << ' ';
	else if(level>1)
	{
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}

//Computing the height of a tree. Longest way from root to
//bottom left or right node.

int height(Node* node)
{
	if(node == NULL)
		return 0;
	else
	{
		//Compute height of each subtree
		int lheight = height(node->left);
		int rheight = height(node->right);

		return ((lheight>rheight) ? ++lheight : ++rheight);
	}
}

Node* newNode(int data)
{
	Node* node = new Node(data);
	//	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}


int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);


	cout << "Level order traversal of a binary tree:" << endl;

	printLevelOrder(root);

	cout << endl;

	return 0;
}
