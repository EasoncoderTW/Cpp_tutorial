#include "stdlib.h"
#include "stdio.h"
#include "LinkedList.hpp"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    list = NULL; // empty address
}
LinkedList::~LinkedList()
{
    clear();
}
// full design

void LinkedList::insert_node(int d, int index)
{
    struct node **current = &list;
    // 1. move
    for(int i = 0;i<index;i++)
    {
        if(*current == NULL)
        {
            cout << "[Error] insert_node: index out of range" << endl;
            exit(1);
        }
        current = &((*current)->next);
    }
    // 2. create new node
    struct node *new_node = new struct node;
    new_node->data = d;
    new_node->next = (*current);
    // 3. 
    (*current) = new_node;
}

int LinkedList::delete_node(int index)
{
    struct node **current = &list;
    // move
    for(int i = 0;i<index;i++)
    {
        if(*current == NULL)
        {
            cout << "[Error] insert_node: index out of range" << endl;
            exit(1);
        }
        current = &((*current)->next);
    }

    int data = (*current)->data; // keep the data to return
    struct node *to_del = (*current);
    (*current) = to_del->next;
    delete to_del;
    return data;
}

void LinkedList::dump()
{
    struct node *a1 = list;
    cout << "[ dump ] "<< endl;
    for(int i = 0; a1 ; i++)
    {
        printf("[%2d] (%d) %5d -> (%d)\n", i, a1, a1->data, a1->next);
        a1=(a1->next);
    }
    cout << endl << endl;
}

void LinkedList::clear()
{
    struct node *next;
    while(list)
    {
        next = list->next;
        delete list;
        list = next;
    }
}

int LinkedList::operator [](int index)
{
    struct node **current = &list;
    // move
    for(int i = 0;i<index;i++)
    {
        if(*current == NULL)
        {
            cout << "[Error] insert_node: index out of range" << endl;
            exit(1);
        }
        current = &((*current)->next);
    }
    return (*current) -> data;
}
