#include "Bank.hpp"

int main()
{
    Bank b1; // 沒有參數就不用加()
    Bank b2("Taipei");
    Bank b3("Tainan","t.log");

    Bank *b4 = new Bank("Tainan");
    delete b4;
    return 0;
}
