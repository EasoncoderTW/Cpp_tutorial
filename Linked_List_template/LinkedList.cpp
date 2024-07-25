#include "stdlib.h"
#include "stdio.h"
#include "LinkedList.hpp"
#include <iostream>
using namespace std;

template<typename T>
LinkedList<T>::LinkedList()
{
    list = NULL; // empty address
}
template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}
// full design
template<typename T>
void LinkedList<T>::insert_node(const T& d, int index)
{
    struct node<T> **current = &list;
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
    struct node<T> *new_node = new struct node<T>;
    new_node->data = d;
    new_node->next = (*current);
    // 3. 
    (*current) = new_node;
}
template<typename T>
T& LinkedList<T>::delete_node(int index)
{
    struct node<T> **current = &list;
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

    T data = (*current)->data; // keep the data to return
    struct node<T> *to_del = (*current);
    (*current) = to_del->next;
    delete to_del;
    return data;
}
template<typename T>
void LinkedList<T>::dump()
{
    struct node<T> *a1 = list;
    cout << "[ dump ] "<< endl;
    for(int i = 0; a1 ; i++)
    {
        printf("[%2d] (%d) %5d -> (%d)\n", i, a1, a1->data, a1->next);
        a1=(a1->next);
    }
    cout << endl << endl;
}
template<typename T>
void LinkedList<T>::clear()
{
    struct node<T> *next;
    while(list)
    {
        next = list->next;
        delete list;
        list = next;
    }
}
template<typename T>
T& LinkedList<T>::operator [](int index)
{
    struct node<T> **current = &list;
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
