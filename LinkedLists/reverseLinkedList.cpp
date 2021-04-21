#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList
{
	Node* head;
	LinkedList()
	{
		head = NULL;
	}

	//Function to reverse linked list

	void reverse()
	{
		//Initiliaze current, prev and next pointers
		Node* current = head;
		Node* prev=NULL,*next = NULL;

		while(current!=NULL)
		{
			//store next
			next = current->next;

			//Reverse current nodes pointer
			current->next = prev;

			//Move pointers ahead
			prev = current;
			current = next;
		}
		head = prev;
	}

	void print()
	{
		struct Node* tmp = head;
		while(tmp != NULL)
		{
			cout << tmp->data << ' ';
			tmp = tmp->next;
		}
	}

	void push(int data)
	{
		Node* tmp = new Node(data);
		tmp->next = head;
		head = tmp;
	}
};

int main()
{
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list is " << endl;
	ll.print();
	cout << endl;

	ll.reverse();

	cout << "Reverse of current linked list is:" << endl;
	ll.print();

	return 0;
}
