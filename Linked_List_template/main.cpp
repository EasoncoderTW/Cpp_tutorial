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

    cout << "Demo Stack Operation" << endl;
    
    Stack<int> S1;
    for(int i = 0;i<10;i++) S1.push(i);
    S1.dump();
    int a = S1.pop(); cout << a << endl;
    a = S1.pop(); cout << a << endl;
    a = S1.pop(); cout << a << endl;
    S1.dump();

    return 0;
}
