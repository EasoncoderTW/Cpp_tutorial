#include "Vector.hpp"

Vector::Vector()
{
    x = 0;
    y = 0;
}
Vector::Vector(int x, int y)
{
    this->x = x;
    this->y = y;
}
int Vector::get_x()
{
    return x;
}
int Vector::get_y()
{
    return y;
}

ostream &operator<<(ostream &o, const Vector &v)
{
    o << "("<< v.x << ", "<<  v.y << ")";
    return o;
}

Vector Vector::operator+(const Vector other)
{
    Vector v;
    v.x = this->x + other.x;
    v.y = this->y + other.y;
    return v;
}

Vector Vector::operator=(const Vector other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Vector Vector::operator*(int other)
{
    Vector r;
    r.x = this->x * other;
    r.y = this->y * other;
    return r;
}

Vector Vector::operator*=(int other)
{
    this->x *= other;
    this->y *= other;
    return *this;
}

Vector operator*(int other,Vector v)
{
    Vector r;
    r.x = v.x * other;
    r.y = v.y * other;
    return r;
}


int Vector::operator*(Vector other)
{
    return this->x * other.x + this->y * other.y;
}
