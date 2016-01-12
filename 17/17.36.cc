#include <iostream>
#include <iomanip>
#include <cmath>
#define THENUM (100 * sqrt(2))
using namespace std;

int main()
{
    cout << "default : " << setw(20) << THENUM << '\n'
         << "hex : " << hexfloat << setw(24) << THENUM << '\n'
         << "scientific : " << scientific << setw(17) << THENUM << '\n'
         << endl;

    return 0;
}
