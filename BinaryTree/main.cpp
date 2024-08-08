#include "binarytree.hpp"
#include <iostream>

using namespace std;

int main()
{
    BinaryTree<int> B;

    B.insert_node(5);
    B.insert_node(2);
    B.insert_node(8);
    B.insert_node(6);
    B.insert_node(4);
    B.insert_node(1);
    B.insert_node(9);

    B.dump();
    cout << "--------------------------------" << endl;

    B.delete_node(5);
    B.dump();

    B.print(PREORDER);
    B.print(INORDER);
    B.print(POSTORDER);

    return 0;
}