#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    typedef string famlname;
    typedef string fname;
    multimap<famlname, fname> namemap;
    famlname family_n;
    fname first_n;

    while(cin >> family_n >> first_n)
        namemap.insert({family_n, first_n});

    for(auto& x : namemap)
        cout << x.first << ' ' << x.second << endl;
}
