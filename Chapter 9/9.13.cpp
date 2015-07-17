#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(void)
{
    vector<int> i_v(10, 5);
    list<int> i_l(10, 4);
    vector<double> d_v(i_v.cbegin(), i_v.cend());

    for(auto x : d_v)
        cout << x << endl;

    d_v.clear();
    d_v.insert(d_v.begin(), i_l.cbegin(), i_l.cend());

    for(auto x : d_v)
        cout << x << endl;

    return 0;
}
