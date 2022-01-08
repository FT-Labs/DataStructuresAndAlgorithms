#include <iostream>
#include "ll.h"
using namespace std;


void reverseLL(Node** head)
{
	Node* current = *head;
	Node* prev = nullptr, *next = nullptr;

	while (current)
	{
		next = current->next;

		current->next = prev;

		prev = current, current = next;
	}
	*head = prev;
}

Node* reverseLLRecursive(Node* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	Node* rest = reverseLLRecursive(head->next);
	cout << head->data << "HERE" << endl;
	head->next->next = head;
	head->next = nullptr;

	return rest;
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

	reverseLL(&head);

	printLL(head);

	head = reverseLLRecursive(head);

	printLL(head);




	return 0;
}
