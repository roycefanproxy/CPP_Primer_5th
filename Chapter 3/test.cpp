#include <iostream>
using namespace std;
int main()
{

    char test[] = "hahaha";
    const char * p = test;
    auto x = const_cast<char *>(p);
    x = test;
    *(p+2) = 'g';
    *x = 'z';
    cout << test << endl;

    return 0;
}
