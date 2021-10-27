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

void insertAfter(Node* prev_node,int new_data)
{
    if(prev_node == NULL)
    {
        std::cout << "Previous node cant be null.";
        return;

    }
    //Create new node
    Node* new_node = new Node();
    //Put in the data
    new_node->data = new_data;
    //Make next of new node as the new of prev node
    new_node->next = prev_node->next;
    //Make prev node to point at new node
    prev_node->next = new_node;
}

void push(Node** head_ref,int new_data)
{
    Node* new_node = new Node();
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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
    push(&head, 0);
    insertAfter(second ,12);

    printList(head);

    return 0;

}
