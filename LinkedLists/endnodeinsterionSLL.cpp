/*
Author: Arda
Company: PhysTech
Date: 9/25/20
*/
#include  <iostream>

class Node{
public:
    int data;
    Node* next;
};

void append(Node** head_ref,int new_data)
{
    Node* new_node = new Node();

    Node *last = *head_ref;
    //Put the data in new node
    new_node->data = new_data;
    new_node->next = NULL;
    //If LL is empty,make the new node as head
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    //Else traverse till last node
    while (last->next != NULL)
    {
        last = last->next;
    }
    //Finally point last node to new node
    last->next = new_node;
    return;
}

void printList(Node* n)
{
    while(n != NULL)
    {
        std::cout << n->data << ' ';
        n = n->next;
    }
}

int main() {

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    append(&head , 4);
    printList(head);

    return 0;

}