#include <bits/stdc++.h>
#include <iostream>
#include <queue>


class Node{
	public:
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data)
{
	Node* newNode = new Node();
	if(!newNode)
	{
		std::cout << "Memory Error!" << std::endl;
		return NULL;
	}

	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node* root,int data)
{
	//If tree is empty, assign node to root
	if(root == NULL)
	{
		root = createNode(data);
		return root;
	}
	std::queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if(temp->left!=NULL)
			q.push(temp->left);
		else {
			temp->left = createNode(data);
			return root;
		}
		if(temp->right!=NULL)
			q.push(temp->right);
		else{
			temp->right = createNode(data);
			return root;
		}
	}
}

void inOrder(Node* temp)
{
	if(temp == NULL)
		return;

	inOrder(temp->left);
	std::cout << temp->data << ' ';
	inOrder(temp->right);

}





int main()
{
	Node* root = createNode(10);
	root->left = createNode(11);
	root->right = createNode(9);
	root->left->left = createNode(7);
	root->right->left = createNode(15);
	root->right->right = createNode(8);

	std::cout << "Inorder traversal before insertion:" ;
	inOrder(root);
	std::cout << std::endl;

	int key = 12;
	insertNode(root,key);
	std::cout << "Inorder traversal after insertion:";
	inOrder(root);
	std::cout << std::endl;

	return 0;
}











