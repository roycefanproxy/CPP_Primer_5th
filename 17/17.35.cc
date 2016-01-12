#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "scientific : " << scientific << 100 * sqrt(2) << '\n'
         << "fixed : " << fixed << 100 * sqrt(2) << '\n'
         << "hexfloat : " << uppercase << hexfloat << 100 * sqrt(2) << '\n'
         << nouppercase
         << "default float : " << defaultfloat << 100 * sqrt(2) << '\n'
         << endl;

    return 0;
}
