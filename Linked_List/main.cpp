#include <iostream>
#include <stdio.h>
#include "LinkedList.hpp"

using namespace std;

int main()
{
    node *Stack = create_stack();
    stack_push(&Stack, 1);
    stack_push(&Stack, 2);
    stack_push(&Stack, 3);
    int p;
    p = stack_pop(&Stack); cout << p << endl;
    p = stack_pop(&Stack); cout << p << endl;
    p = stack_pop(&Stack); cout << p << endl;
    return 0;
}