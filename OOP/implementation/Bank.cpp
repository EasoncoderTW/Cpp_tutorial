#include "Bank.hpp"
#include <iostream>

using namespace std;

Bank::Bank(): name("<Unknown>"),log_path("Unknown.log")
{
    cout << "Constructor 1 " << endl;
}

Bank::Bank(string name):name(name),log_path(name+".log")
{
    cout << "Constructor 2 " << endl;
}

Bank::Bank(string name, string log_path):name(name),log_path(log_path)
{
    cout << "Constructor 3 " << endl;
}

Bank::~Bank()
{
    cout << "Destructor " << endl;
}
