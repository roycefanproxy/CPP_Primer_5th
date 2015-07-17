#include <iostream>
#include "7.27.h"
using namespace std;

int main()
{
    Screen test(5, 5, 'X');
    test.move(4, 0).set('#').display(cout);
    cout << "\n";
    test.display(cout);
    cout << "\n";

    return 0;

}
