#include <iostream>

#ifndef MAX_SCORE
#define MAX_SCORE 100
#endif

using namespace std;

int main()
{
    cout << "Enter a score"  << endl;
    int c;
    cin >> c;

    if(c >= MAX_SCORE)
    {
        cout << "Out of range" << endl;
    }
    return 0;
}