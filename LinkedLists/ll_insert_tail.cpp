#include <iostream>
#include "ll.h"
using namespace std;


void insertTail(Node* head, int data)
{
	Node** indirect = &head;

	while ((*indirect)->next != nullptr)
		indirect = &(*indirect)->next;

	(*indirect)->next = new Node(data);
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

	insertTail(head, 51);
	insertTail(head, 22);

	printLL(head);

	delete head, second, third, fourth;

	return 0;
}
