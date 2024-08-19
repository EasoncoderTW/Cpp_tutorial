#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

template<typename T>
struct fileop
{
    T (*read)(string fileanme);
    void (*write)(string fileanme, T);
};

#define CREATE_READFN(type, implement) \
type read_file_##type(string filename) \
{ \
    type s; \
    ifstream file; \
    file.open(filename, ios::in); \
    if(!file) exit(0); \
    implement \
    file.close(); \
    return s; \
}

#define CREATE_WRITEFN(type, implement) \
void write_file_##type(string filename, type s) \
{ \
    ofstream file; \
    file.open(filename, ios::out); \
    implement \
    file.close(); \
}

#define FILE_SUPPORT(type, read_implement, write_implement)\
    CREATE_READFN(type, read_implement) \
    CREATE_WRITEFN(type, write_implement) \
    struct fileop <type> type##_op = {.read = read_file_##type,.write = write_file_##type};

#define FILE_SUPPORT_DEFULT(type)\
    FILE_SUPPORT(type, file >> s;, file << s << endl;)


FILE_SUPPORT_DEFULT(int)
FILE_SUPPORT(string, getline(file, s);, file << s << endl;)

typedef struct{
    string name;
    string email;
    int age;
}mytype;

FILE_SUPPORT(mytype, \
file >> s.name >> s.email >>s.age;, \
file << s.name << " " <<  s.email << " " << s.age<< endl;)

int main()
{
    // string_op.write("./out.txt", "Hello world");
    // cout << string_op.read("./out.txt") << endl;
    mytype a = {"Eason","xxx@.gmail.com",22};

    mytype_op.write("./out.txt", a);

    mytype b = mytype_op.read("./out.txt");

    cout << b.name << " " << b.email << " "<<  b.age << endl;
    return 0;
}