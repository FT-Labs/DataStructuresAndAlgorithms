#include <iostream>
#include "ll.h" // Look into header file for linked list representation
using namespace std;


void insertHead(Node** head, int data)
{
	Node* newHead = new Node(data);
	newHead->next = *head;
	*head = newHead;
}


int main()
{
	Node* head = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);

	head->next = second;
	second->next = third;

	printLL(head);

	insertHead(&head, 5);

	printLL(head);

	delete head;
	delete second;
	delete third;

	return 0;
}
