#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "stdlib.h"
#include "stdio.h"
#include <iostream>
using namespace std;

enum {
    PREORDER,INORDER,POSTORDER
};

template <typename T>
struct node
{
    T data;
    struct node *left;
    struct node *right;
};

template <typename T>
class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();
        void insert_node(const T d);
        bool delete_node(const T d);
        void dump(); // 把所有資訊印出來 (like a tree)
        void clear();
        void print(int order); // 只把 data 輸出(依照 order 給予的方式輸出)
        bool exist(const T d);
    protected:
        struct node<T>* tree; // head of list
        void dump_(struct node<T> *t,int level);
        void clear_(struct node<T> *t);
        void print_in(struct node<T> *t);
        void print_pre(struct node<T> *t);
        void print_post(struct node<T> *t);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
    tree = NULL;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    clear();
}

template <typename T>
void BinaryTree<T>::insert_node(const T d)
{
    struct node<T> **p;
    p = &tree;

    while(*p) // 該空間已經有 node
    {
        // 需要決定往左邊還是往右邊走
        if(d < (*p)->data)
        {
            p = &((*p)->left);
        }
        else
        {
            p = &((*p)->right);
        }
    }

    // 該空間為 NULL (leaf)
    *p = new struct node<T>;
    (*p)->data = d;
    (*p)->left = NULL;
    (*p)->right = NULL;
}

template <typename T>
bool BinaryTree<T>::delete_node(const T d)
{
    struct node<T> **p;
    p = &tree;

    while(*p) // 該空間已經有 node
    {
        if(d == (*p)->data) // 找到該 node
        {
            break;
        }
        else if(d < (*p)->data) // 需要決定往左邊還是往右邊走
        {
            p = &((*p)->left);
        }
        else
        {
            p = &((*p)->right);
        }
    }

    if(*p == NULL) // node 不存在
    {
        return  false;
    }

    // find the node to swap
    struct node<T> **q = p; // q 從 p 出發尋找可以頂替 p 的 node

    while(1)
    {
        if((*p)->right){ // 要被刪除的 node 右邊如果有節點
            q = &((*p)->right); // 踏上右節點
            while((*q)->left){q = &((*q)->left);} // 尋找右節點的最左節點
        }
        else if((*p)->left){ // 要被刪除的 node 左邊如果有節點
            q = &((*p)->left); // 踏上左節點
            while((*q)->right){q = &((*q)->right);} // 尋找左節點的最右節點
        }else{
            // 沒有可以頂替的 q
            break;
        }
        (*p)->data = (*q)->data;
        p = q; // 再嘗試找可以頂替 p 的 q
    }
    delete *p;
    *p = NULL;
}
template <typename T>
void BinaryTree<T>::dump()
{
    dump_(tree, 0);
}

template <typename T>
void BinaryTree<T>::dump_(struct node<T> *t,int level)
{
    if(!t) return;
    dump_(t->left, level+1);
    for(int i = 0;i<level;i++){cout << "    ";}
    cout << "[Data] " << t->data << " [Left] " << t->left << " [Right] " << t->right << endl;
    dump_(t->right, level+1);
}

template <typename T>
void BinaryTree<T>::clear()
{
    clear_(tree);
    tree = NULL;
}

template <typename T>
void BinaryTree<T>::clear_(struct node<T> *t)
{
    if(t == NULL) return;
    clear_(t->left);
    clear_(t->right);
    delete t;
}

template <typename T>
void BinaryTree<T>::print(int order)
{
    switch (order)
    {
    case INORDER:
        print_in(tree);
        break;
    case PREORDER:
        print_pre(tree);
        break;
    case POSTORDER:
        print_post(tree);
        break;
    default:
        break;
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::print_pre(struct node<T> *t)
{
    if(t == NULL) return;
    cout << t->data << " ";
    print_pre(t->left);
    print_pre(t->right);
}

template <typename T>
void BinaryTree<T>::print_in(struct node<T> *t)
{
    if(t == NULL) return;
    print_in(t->left);
    cout << t->data << " ";
    print_in(t->right);
}

template <typename T>
void BinaryTree<T>::print_post(struct node<T> *t)
{
    if(t == NULL) return;
    print_post(t->left);
    print_post(t->right);
    cout << t->data << " ";
}

template <typename T>
bool BinaryTree<T>::exist(const T d)
{
    struct node<T> **p;
    p = &tree;

    while(*p) // 該空間已經有 node
    {
        if(d == (*p)->data) // 找到該 node
        {
            break;
        }
        else if(d < (*p)->data) // 需要決定往左邊還是往右邊走
        {
            p = &((*p)->left);
        }
        else
        {
            p = &((*p)->right);
        }
    }

    if(*p == NULL) // node 不存在
    {
        return  false;
    }
    return true;
}

/* insert node - sort*/

/* delete node - search & sort(reorder) */

/* find - search */

/* clean */

/* print - representation (pre-order/in-order/post-order) */


#endif
