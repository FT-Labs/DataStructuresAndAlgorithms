/*
Author: Arda
Company: PhysTech
Date: 9/24/20
*/
#include  <iostream>

class Node{
public:
    int data;
    Node* next;
};

void printTraversalLinkedList(Node* n)
{
    while(n!= NULL)
    {
        std::cout << n->data << ' ';
        n = n->next;
    }
}

int main() {

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    printTraversalLinkedList(head);

    return 0;

}