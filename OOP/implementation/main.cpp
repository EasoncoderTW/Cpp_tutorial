#include "Bank.hpp"

int main()
{
    Bank b1; // 沒有參數就不用加()
    Bank b2("Taipei");
    Bank b3("Tainan");

    //Bank *b4 = new Bank("Kaoshiung");
    //delete b4;

    b1.Create("Eason", 1000);

    b2.Create("Eason", 1000);
    b2.Create("Billy", 200);

    b3.Create("Eason", 2000);

    b2.Withdraw("Eason",500);
    b3.Withdraw("Billy",500);
    b2.Withdraw("Billy",500);

    return 0;
}
