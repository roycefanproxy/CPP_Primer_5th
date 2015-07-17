#include <iostream>
#include <cstdlib>
using namespace std;

int func(string s);
int func(int);
double func(double);

int (*cr8_arr(void))[10];
int main()
{
    auto ctr = 0;
    auto arr = cr8_arr();
    for(int r = 0; r < 5; ++r)
        for(int c = 0; c < 10; ++c)
            arr[r][c] = ++ctr;

    for(auto x = 0; x < 5; ++x)
    {
        for(auto y = 0; y < 10; ++y)
            cout << arr[x][y] << ' ';
        cout << endl;
    }
    cout << endl;
    func(5.82);
    func(100);
    func("The string type.");

    return 0;
}

int (*cr8_arr(void))[10]
{
    static int arr[5][10];

    return arr;
}

int func(string n)
{
    cout << n << endl;

    return 1;
}
int func(int n)
{
    cout << "This is int type of " << n << endl;
    return n;
}

double func(double n)
{
    cout << "This is double type of " << n << endl;

    return n;
}
