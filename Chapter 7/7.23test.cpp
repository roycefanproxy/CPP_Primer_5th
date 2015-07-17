#include <iostream>
#include "7.23.h"
using namespace std;

int main()
{
    Screen test(22, 100);

    test.set('a');
    test.set('b');
    for(auto c = 'c'; c != 'z' + 1; ++c)
        test.set(c);
    test.print(cout);


    Screen test2(22, 100, 'c');
    test2.print(cout);

    cout << "Done." << endl;

    return 0;
}
