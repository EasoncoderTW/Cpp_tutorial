#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP


template <typename T>
struct node
{
    T data;
    struct node *next;
};

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insert_node(const T& d, int index);
        T& delete_node(int index);
        void dump();
        void clear();
        T& operator [](int index); // peek
    private:
        struct node<T>* list; // head of list
};



#endif