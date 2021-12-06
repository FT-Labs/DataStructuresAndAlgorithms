#include <iostream>
#include "ll.h"
using namespace std;

// insert after with data
void insertAfter(Node* head, int after, int data)
{
	Node** indirect = &head;

	while (*(indirect) && (*indirect)->data != after)
		indirect = &(*indirect)->next;

	if (*(indirect) == nullptr) return;

	Node* newNode = new Node(data);

	newNode->next = (*indirect)->next;
	(*indirect)->next = newNode;
}

// insert after with Node*
void insertAfter(Node* head, Node* after, int data)
{
	Node** indirect = &head;

	while (*indirect && (*indirect) != after)
		indirect = &(*indirect)->next;

	if (!(*indirect)) return;

	Node* newNode = new Node(data);

	newNode->next = (*indirect)->next;
	(*indirect)->next = newNode;
}


int main()
{
	Node* head = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	Node* fourth = new Node(4);

	head->next = second;
	second->next = third;
	third->next = fourth;

	printLL(head);

	insertAfter(head, 1, 5);
	insertAfter(head, 5, 18);
	// check for non existing value
	insertAfter(head, 50, 18);

	printLL(head);

	insertAfter(head, third, 11);
	insertAfter(head, new Node(8), 11);

	printLL(head);

	delete head, second, third, fourth;

	return 0;
}
