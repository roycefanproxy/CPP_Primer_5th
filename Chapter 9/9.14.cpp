#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(void)
{
    char d[] = "test";
    list<char *> cp_l(10, d);
    vector<string> s_v(cp_l.cbegin(), cp_l.cend());

    for(auto x : s_v)
        cout << x << endl;

    s_v[5] = "fuck";

    for(auto x : s_v)
        cout << x << endl;
    return 0;
}
