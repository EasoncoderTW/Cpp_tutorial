#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
    Vector v1(1,2);
    Vector v2(3,5);
    //cout << v1.get_x() << ", " << v1.get_y() << endl;
    //cout << v2.get_x() << ", " << v2.get_y() << endl;

    cout << v1 << endl;   
    cout << v2 << endl;

    //operator<<(cout, v1);
    //operator<<(cout, v2);

    cout << v1 << v2 << endl;

    Vector v3 = v1 + v2;
    Vector v4,v5;
    v5 = v4 = v3; //v5.operator=(v4.operator=(v3));
    cout << v3 << endl;

    v4 = 3 * v4;
    cout << v4 << endl;
    

    v5 = v5 * 2;
    cout << v5 << endl;

    v5 *= 2;
    cout << v5 << endl;
    

    int t = v4 * v5;
    cout << t << endl;


    return 0; 
}


// 3x^2 + 2x^1 + 1
// 5x^2 + 9x^1 + 8
/*
Poly a,b;
Poly a("5x^2 + 9x^1 + 8");
cin >> a;
cin >> b;
cout << a + b;
cout << a * b;
*/
