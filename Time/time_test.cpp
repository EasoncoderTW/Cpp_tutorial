#include <time.h>
#include <iostream>

using namespace std;

int main()
{
    time_t t = time(NULL);
    cout << t << endl;

    struct tm *tm_1 = localtime(&t);
    cout << "[year] " << tm_1->tm_year + 1900 << endl;
    cout << "[mon] " << tm_1->tm_mon + 1<< endl;
    cout << "[mday] " << tm_1->tm_mday << endl;
    cout << "[yday] " << tm_1->tm_yday << endl;
    cout << "[hour] " << tm_1->tm_hour << endl;
    cout << "[min] " << tm_1->tm_min << endl;
    cout << "[sec] " << tm_1->tm_sec << endl;
    cout << "[isdst] " << tm_1->tm_isdst << endl;
    cout << "[wday] " << tm_1->tm_wday << endl;

    cout << ctime(&t) << endl;

    char s[128];
    int i = strftime(s,128,"[%Y/%m/%d %a %H:%M:%S]",tm_1);
    cout << s << " Use " << i << " chars"<< endl;

    return 0;
}

