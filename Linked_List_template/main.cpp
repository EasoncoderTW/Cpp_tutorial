#include <iostream>
#include <stdio.h>
#include "LinkedList.hpp"
#include "Vector.hpp"
using namespace std;

int main()
{
    LinkedList<Vector> L1;
    Vector v(3,5);
    L1.insert_node(v,0);
    v *= 2;
    L1.insert_node(v,0);
    L1.dump();

    cout << L1[1] << endl;

    L1.clear();
    L1.dump();
    return 0;
}
