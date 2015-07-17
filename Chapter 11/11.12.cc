#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string input1;
    int input2;
    vector<pair<string, int>> vp;

    while(cin >> input1 >> input2)
        vp.push_back({input1, input2});

    for(auto& x : vp)
        cout << x.first << ' ' << x.second << endl;

    return 0;
}
