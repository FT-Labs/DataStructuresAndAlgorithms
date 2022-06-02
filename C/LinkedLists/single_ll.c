#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int val;
    Node *next;
};

Node *create_node(int val)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->val = val;
    return new_node;
}

void free_list(Node *head)
{
    Node *prev = head;
    while (head)
    {
        head = head->next;
        free(prev);
        prev = head;
    }
}

void insert_before(Node **head, int val, int before)
{
    Node *new_node = create_node(val);
    Node **indirect = head;

    while((*indirect)->val != before)
        indirect = &(*indirect)->next;

    new_node->next = (*indirect);
    (*indirect) = new_node;
}

void erase(Node **head, int val)
{
    Node **indirect = head;
    while ((*indirect)->val != val)
        indirect = &(*indirect)->next;
    Node *to_remove = *(indirect);
    (*indirect) = (*indirect)->next;
    free(to_remove);
}

void print_list(Node *head)
{
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("\n");
}


int main ()
{
    Node *head = create_node(1);
    Node *second = create_node(2);
    Node *third = create_node(3);
    Node *fourth = create_node(4);
    Node *tail = create_node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = tail;

    insert_before(&head, 8, 2);
    print_list(head);
    insert_before(&head, 11, 1);
    print_list(head);

    erase(&head, 11);
    print_list(head);


    free_list(head);

    return 0;
}
