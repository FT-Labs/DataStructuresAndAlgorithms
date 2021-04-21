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


void printList(Node* n)
{
    while(n!=NULL)
    {
        std::cout << n->data << ' ';
        n = n->next;
    }
}
void push(Node** head_ref,int new_data)
{
    //1- Create new node
    Node* new_node = new Node();
    //2- Put the data
    new_node->data = new_data;
    //3- Set new nodes pointer to point at head node
    new_node->next = (*head_ref);
    //4- Move the head to point new node
    (*head_ref) = new_node;

}



int main() {


    Node* head = NULL;
    Node* second = NULL;

    head = new Node();
    second = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = NULL;

    //Pushing the new node
    push(&head,5);

    printList(head);

    return 0;


}
