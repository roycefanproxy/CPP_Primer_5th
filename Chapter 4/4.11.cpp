#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;
    while(!(a > b && b > c && c > d))
        cin >> a >> b >> c >> d;

    cout << "Done." << endl;

    return 0;
}
