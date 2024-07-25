#include <iostream>
#include <stdio.h>
#include "LinkedList.hpp"
using namespace std;

int main()
{
    LinkedList<int> L1;
    L1.insert_node(10,0);
    L1.insert_node(20,0);
    L1.dump();

    cout << L1[1] << endl;

    L1.clear();
    L1.dump();
    return 0;
}
