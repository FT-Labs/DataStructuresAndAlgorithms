#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int data):data(data)
	{
		this->left = nullptr;
		this->right = nullptr;
	}

	Node(){}
};


bool pathToSum(Node* node, int sum)
{
	if(node==nullptr)
		return (sum==0);
	else
	{
		// Long solution

		/*bool ans = false;
		int subSum = (node->data > 0 ? sum-node->data : sum+node->data);

		//If a leaf node is reached and sum is 0 return true
		if(subSum == 0 && node->left == nullptr && node->right == nullptr)
			return true;

		cout << subSum << endl;

		//Otherwise check all subtrees
		if(node->left)
			ans = ans || pathToSum(node->left,sum);
		if(node->right)
			ans = ans || pathToSum(node->right,sum);

		return ans;*/

		//Short solution

		sum -= node->data;
		return pathToSum(node->left, sum) || pathToSum(node->right, sum);
	}
}





int main()
{
	Node* root = new Node(4);
	root->left = new Node(1);
	root->left->left = new Node(-2);
	root->left->left->right = new Node(3);
	root->right = new Node(3);
	root->right->left = new Node(1);
	root->right->right = new Node(2);
	root->right->right->left = new Node(-2);
	root->right->right->right = new Node(-3);



	cout << pathToSum(root,7) << endl;

	return 0;
}
