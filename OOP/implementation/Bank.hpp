#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

typedef struct 
{
    double money;
    string name;
}BankAccount;


class Bank{
private:
    string name;
    vector <BankAccount> accounts;
    string log_path;
    void log(string s);
public:
    Bank(); // Constructor (classname)
    Bank(string name);
    Bank(string name, string log_path);
    ~Bank(); // Destructor ("~"+classname)

    void Create(string name);
    void Create(string name,double money);

    void Save(string name,double money);
    void Withdraw(string name,double money);
};