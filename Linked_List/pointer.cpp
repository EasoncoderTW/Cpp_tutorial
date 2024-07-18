#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct
{
    int a;
    int b;
}ttt;

int main()
{
    //char c[4] = {'0',49,0x32,0x0}; // "012"
    /*char c[10] = "012345678";
    c[5] = 9;
    cout << c << endl;*/

    char b[14] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,-120,0x66,0x55,0x44,0x33,0x22,0x11};
    int* p = (int*)(&b[3]);

    printf("[%d] 0x%x\n", p,*p);
    printf("[%d] 0x%x\n", (p+1), *(p+1)); // 0x88 -> 136 -> 136-2^8 = -120

    ttt *t = (ttt*)(&b[3]);
    printf("0x%x\n",t->a);
    printf("0x%x\n",t->b);
    
    char a = -120; // 56
    cout << a << endl;
    printf("%d\n", a);
    printf("0x%x\n", a);
    

    return 0;
}