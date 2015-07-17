#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    map<int, int> msi;
    for(int i = 0; i != 21; ++i)
        msi[i] = 0;
    int input;
    while(cin >> input)
        msi.begin()->second = input;

    for(auto x : msi)
        cout << x.first << ' ' << x.second << endl;
}
