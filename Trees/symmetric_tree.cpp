#include <iostream>
#include <vector>
using namespace std;


string c1 = "";
string c2 = "";
bool flag = true;


class Node
{
	public:
		int value;
		Node* left;
		Node* right;

	Node(int value):value(value)
	{
		this->left = nullptr;
		this->right = nullptr;
	}

	Node()
	{}
};


bool isSymmetric(Node* r1,Node* l1)
{
	if(r1==nullptr && l1==nullptr) return true;
	if(r1==nullptr || l1==nullptr) return false;

	return (r1->value == l1->value) && isSymmetric(r1->left,l1->right) && isSymmetric(r1->right,l1->left);
}





int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(2);
	root->left->right = new Node(4);
	root->left->left = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(3);

	cout << isSymmetric(root,root) << endl;




	return 0;
}
