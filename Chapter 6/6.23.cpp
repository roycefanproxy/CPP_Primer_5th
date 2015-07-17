#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>
using namespace std;

int print(int);
int* print(int (&)[2]);
int main()
{
    srand((unsigned) time(0));
    int j[] = {rand(), rand()};
    int i = 0;

    print(i);
    print(j);
    return 0;
}

int print(int x)
{
    cout << x << endl;

    return x;
}

int *print(int (&pt)[2])
{
    for(auto x = begin(pt); x != end(pt); ++x)
        cout << *x << ' ';
    cout << endl;

    return pt;
}
