/*
Author: Arda
Company: PhysTech
Date: 9/26/20
*/
#include  <iostream>


class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

void push(Node** headRef,int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headRef);
    newNode->prev = NULL;

    if (*headRef!=NULL)
        (*headRef)->prev = newNode;

    (*headRef) = newNode;

}



void printListForward(Node* headRef)
{
    std::cout << "Forward List:";
    while (headRef != NULL)
    {
        std::cout << headRef->data << ' ';
        headRef = headRef->next;
    }
}


void append(Node** headRef, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if(*headRef == NULL)
    {
        newNode->prev = NULL;
        (*headRef) = newNode;
        return;
    }

    Node* last = *headRef;

    while (last->next!= NULL)
    {
       last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
    return;

}

void insertAfter(Node* prevNode, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;

    if(prevNode == NULL)
        return;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    prevNode->next = newNode;

    if(newNode->next != NULL)
        newNode->next->prev = newNode;
    return;
}


void deleteNode(Node** headRef, Node* del)
{
    if(*headRef == NULL || del == NULL)
        return;

    if(*headRef == del)
        *headRef = del->next;

    //Change next if the deleted node isn't the last node
    if(del->next != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}



void printListReverse(Node* tailRef)
{
    std::cout << "Reversed List:";
    while(tailRef != NULL)
    {
        std::cout <<  tailRef->data << ' ';
        tailRef = tailRef->prev;
    }
}


int main() {

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->next = NULL;
    third->prev = second;

    push(&head , 51);
    printListReverse(third);
    printListForward(head);



    return 0;
}
