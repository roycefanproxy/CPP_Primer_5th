#include <iostream>
using namespace std;

int func(int, int);

int main()
{
    int value, input;

    while(cin >> value >> input)
        cout << func(value, input) << endl;

    return 0;
}

int func(int a, int b)
{
    auto x = [=] (int c) { return a + c; };

    return x(b);
}
