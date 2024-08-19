#include <iostream>

using namespace std;

struct rwfunc
{
    void (*read)(int); // function 格式
    void (*write)(int);
};

void read_function(int a)
{
    cout << "Read:" << a << endl;
}

void write_function(int a)
{
    cout << "Write:" << a << endl;
}

void old_function(int a)
{
    cout << "Old:" << a << endl;
}

int main(int argc, char const *argv[])
{
    struct rwfunc fn={read_function,old_function};
    fn.read(2);
    fn.write(2);

    // void (*func)(int) = read_function;
    // read_function(2);
    // func(2);

    return 0;
}
