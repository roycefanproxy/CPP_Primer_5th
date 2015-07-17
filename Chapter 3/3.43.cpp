#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int test[2][40];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 40; j++)
            test[i][j] = j + 1;

    cout << "pointer type for" << endl;
    for(int (*x)[40] = test; x != test + 2; x++)
        for(int *y = *x; y != *x + 40; y++)
            cout << *y << endl;

    cout << "subscript type for" << endl;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 40; j++)
            cout << test[i][j] << endl;

    cout << "range type for" << endl;
    for(int (&x)[40] : test)
        for(int y : x)
            cout << y << endl;

    return 0;
}

