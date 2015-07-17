#include <iostream>
#include "7.32.h"
using namespace std;

int main(void)
{
    Window_mngr test;

    Screen t(10, 20, 'X');
    auto x = test.addScreen(t);
    test.get(x).display(cout);
    test.clear(x);
    test.get(x).display(cout);
}
