#ifndef LL_H
#include <iostream>
#define LL_H
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
}; typedef struct Node Node;

void printLL(Node* head)
{
	while (head != nullptr)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

#endif /* LL_H */
