#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP


struct node
{
    int data;
    struct node *next;
};

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insert_node(int d, int index);
        int delete_node(int index);
        void dump();
        void clear();
        int operator [](int index); // peek
    private:
        struct node* list; // head of list
};

#endif