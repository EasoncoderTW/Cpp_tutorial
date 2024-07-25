#include <iostream>
using namespace std;

class Vector
{
    private:
        int x;
        int y;
    public:
        Vector();
        Vector(int x, int y);
        int get_x();
        int get_y();

        friend ostream &operator<<(ostream &o, const Vector &v); // 以第三人稱角度協助呼叫

        Vector operator+(const Vector other); // 以第一人稱角度完持實作

        Vector operator=(const Vector other); // 以第一人稱角度完持實作
        Vector operator*(int other); // 以第一人稱角度完持實作
        Vector operator*=(int other); // 以第一人稱角度完持實作
        friend Vector operator*(int other,Vector v); // 以第三人稱角度協助呼叫
        
        int operator*(Vector other); // 內積
        

};