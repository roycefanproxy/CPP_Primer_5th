#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int va = 1;
    int test[2][40];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 40; j++)
            test[i][j] = va++;

    cout << "pointer type for" << endl;
    for(auto x = test; x != test + 2; x++)
        for(auto y = *x; y != *x + 40; y++)
            cout << *y << endl;

    cout << "subscript type for" << endl;
    for(auto i = 0; i < 2; i++)
        for(auto j = 0; j < 40; j++)
            cout << test[i][j] << endl;

    cout << "range type for" << endl;
    for(auto &x : test)
        for(auto y : x)
            cout << y << endl;

    return 0;
}
