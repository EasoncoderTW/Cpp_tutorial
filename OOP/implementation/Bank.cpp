#include "Bank.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Bank::Bank(): name("<Unknown>"),log_path("Unknown.log")
{
    cout << "Constructor 1 "<< name << endl;
    log("Bank "+name+" Create.");
}


Bank::Bank(string name):name(name),log_path(name+".log")
{
    cout << "Constructor 2 "<< name << endl;
    log("Bank "+name+" Create.");
}

Bank::Bank(string name, string log_path):name(name),log_path(log_path)
{
    cout << "Constructor 3 "<< name << endl;
    log("Bank "+name+" Create.");
}

Bank::~Bank()
{
    cout << "Destructor "<< name << endl;
    for(auto a:accounts)
    {
        cout << "\t" << a.name  << " $" << a.money << endl;
    }
    
    ofstream file(log_path, ios::app);
    file << "Bank "<< name << endl;
    for(auto a:accounts)
    {
        file << "\t" << a.name  << " $" << a.money << endl;
    }
    file.close();
    
}

void Bank::log(string s)
{
    /* get time string */
    char ts[128];
    time_t t = time(NULL);
    strftime(ts,128,"[%Y/%m/%d %a %H:%M:%S]",localtime(&t));

    ofstream file(log_path, ios::app); // over write
    file << "["<< ts << "] "<< s << endl;
    file.close();
}


void Bank::Create(string name)
{
    for(auto acc:accounts)
    {
        if(name == acc.name){
            cout << "[Failed] Account exists." << endl;
            return;
        }
    }
    BankAccount b;
    b.money = 0;
    b.name = name;
    accounts.push_back(b);
    log("[Bank "+this->name+"] Create Account "+b.name);
}
void Bank::Create(string name,double money)
{
    for(auto acc:accounts)
    {
        if(name == acc.name){
            cout << "("<< name <<") [Failed] Account exists." << endl;
            return;
        }
    }
    BankAccount b;
    b.money = money;
    b.name = name;
    accounts.push_back(b);
    log("[Bank "+this->name+"] Create Account "+b.name);
}

void Bank::Save(string name,double money)
{
    for(int i =0;i<accounts.size();i++)
    {
        if(accounts[i].name == name){
            accounts[i].money += money;
            log("[Bank "+this->name+"] [Account "+name+"] Save "+to_string(money));
            return;
        }
    }
    cout << "("<< name <<") [Failed] Account does not exist." << endl;
    

}
void Bank::Withdraw(string name,double money)
{
    for(int i =0;i<accounts.size();i++)
    {
        if(accounts[i].name == name){
            if(accounts[i].money >= money)
            {
                accounts[i].money -= money;
                log("[Bank "+this->name+"] [Account "+name+"] Save "+to_string(money));
            }
            else
            {
                cout << "[Failed] ("<< name <<") Money is not enough." << endl;
            }
            return;
        }
    }
    cout << "[Failed] ("<< name <<") Account does not exist." << endl;
}
