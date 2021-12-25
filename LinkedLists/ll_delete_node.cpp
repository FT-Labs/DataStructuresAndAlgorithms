#include <iostream>
#include "ll.h" // Look to this file for linked list representation
using namespace std;




// The cool way to handle, AKA Linus Torvalds taste
void deleteNode(Node** head, Node* entry)
{
	Node** indirect = head;

	while ((*indirect) != entry)
		indirect = &(*indirect)->next;

	*indirect = entry->next;
	delete entry;
}

// Deletion with data
void deleteNode(Node** head, int data)
{
	Node** indirect = head;
	Node* tmp = nullptr;

	while ((*indirect)->data != data && (*indirect) != nullptr)
		indirect = &(*indirect)->next, tmp = *indirect;

	*indirect = (*indirect)->next;
	delete tmp;
}

// CS101 way
void deleteNodeForNormies(Node** head, Node* entry)
{
	Node* prev = nullptr;
	Node* walk = *head;

	while (walk != entry)
	{
		prev = walk;
		walk = walk->next;
	}

	if (!prev)
		*head = entry->next;
	else
		prev->next = entry->next;

	delete entry;
}

// Deletion by using data
void deleteNodeForNormies(Node** head, int data)
{
	Node* prev = nullptr;
	Node* walk = *head;

	if (walk != nullptr && walk->data == data)
	{
		*head = walk->next;
		delete walk;
		return;
	}

	while (walk->data != data && walk != nullptr)
	{
		prev = walk;
		walk = walk->next;
	}

	if (!walk)
		return;

	prev->next = walk->next;

	delete walk;
}


int main()
{
	Node* head = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	Node* fourth = new Node(4);
	Node* fifth = new Node(5);

	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;

	printLL(head);

	//deleteNodeForNormies(&head, head);
	deleteNode(&head, head);

	printLL(head);


	// Clear heap
	delete head;
	delete second;
	delete third;
	delete fourth;
	delete fifth;

	return 0;
}
