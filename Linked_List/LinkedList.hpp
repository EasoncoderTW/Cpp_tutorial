#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *next;
}node;

node* create_stack()
{
    return NULL; // empty address
}
void stack_push(node **head, int d)
{
    node *new_node = new node;
    new_node->data = d;
    new_node->next = (*head);
    (*head) = new_node;
}
int stack_pop(node **head)
{
    ;
}