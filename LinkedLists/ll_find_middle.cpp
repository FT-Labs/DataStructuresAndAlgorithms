#include <iostream>
#include "ll.h"
using namespace std;


int middleNode(Node* head)
{
	Node* slow = head, *fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}



int main()
{
	Node* head = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	Node* fourth = new Node(4);
	Node* tail = new Node(5);

	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = tail;

	cout << middleNode(head) << endl;

	delete head;
	delete second;
	delete third;
	delete fourth;
	delete tail;


	return 0;
}
