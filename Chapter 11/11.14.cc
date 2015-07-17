#include <utility>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef string family_name;
typedef string first_name;
typedef string dof;
int main()
{
    map<family_name, vector<pair<first_name, dof>>> mfvp;
    string famname, fname, birthday;

    while(cin >> famname >> fname >> birthday)
        mfvp[famname].push_back({fname, birthday});

    for(auto& x : mfvp)
        for(auto& y : x.second)
            cout << x.first << ' ' << y.first << ' ' << y.second << endl;

    return 0;
}
