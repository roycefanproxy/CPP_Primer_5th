#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    int value = 42;
    auto f = [&value] () { return ++value; };
    value = 0;
    cout << f() << endl;
}
