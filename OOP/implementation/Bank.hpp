#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct 
{
    double money;
    string name;
    int id;
}BankAccount;


class Bank{
private:
    string name;
    vector <BankAccount> accounts;
    string log_path;
public:
    Bank(); // Constructor (classname)
    Bank(string name);
    Bank(string name, string log_path);
    ~Bank(); // Destructor ("~"+classname)
};