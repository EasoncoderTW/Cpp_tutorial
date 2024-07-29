#ifndef FUNC_HPP
#define FUNC_HPP

#include <iostream>

using namespace std;

#ifdef DEBUG
    #define CREATE_FUNCTION(name) \
    void func##name(void)\
    {\
        cout << "[DEBUG VIRSION ]hello " << #name << endl; \
    }
#else
    #define CREATE_FUNCTION(name) \
    void func##name(void)\
    {\
        cout << "hello " << #name << endl; \
    }
#endif

#define loop(a,b) for(int i = a;i < b;i++)

#endif