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

void push(Node** headRef,int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;

    newNode->next = *headRef;
    (*headRef) = newNode;
    return;
}

void append(Node* headRef,int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;


    while(headRef->next != NULL)
    {
       headRef = headRef->next;
    }

    headRef->next = newNode;
    return;

}

void insertAfter(Node* prevNode, int newData)
{
    Node* newNode = new Node();
    newNode->next = prevNode->next;
    newNode->data = newData;
    prevNode->next = newNode;
    return;
}

void deleteNode(Node** headRef,int key)
{
    Node* temp = *headRef,*prev;

    //If head node holds the key, delete head node
    if(temp!=NULL && temp->data == key)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }

    //Search for the key, keep changing temp->next
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    //If key not in list
    if (temp == NULL) return;

    //Unlink the node
    prev->next = temp->next;
    free(temp);
    return;

}

void deleteNodeAtPosition(Node** headRef,int position)
{
    //If list is empty return
    if(*headRef == NULL)
        return;

    Node* temp = *headRef;

    //If head needs to be removed
    if(position == 0)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }

    for(int i=0;temp!=NULL && i<position-1;++i)
        temp = temp->next;

    //If position is more than nodes
    if(temp == NULL || temp->next == NULL)
        return;

    Node* next = temp->next->next;

    //Unlink the node free memory
    free(temp->next);
    temp->next = next; //Unlink the deleted node from linked list

}

void deleteLinkedList(Node** headRef)
{
    Node* current = *headRef;
    Node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;

}



void printList(Node* last)
{
   while(last!= NULL)
   {
       std::cout << last->data << ' ';
       last = last->next;
   }
}

int main() {

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;

    push(&head,3);
    append(head,22);

    deleteNode(&head,3);
    deleteNode(&head , 22);
    printList(head);
    return 0;

}
