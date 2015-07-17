#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void elidups(vector<string>&);
int main()
{
    vector<string> vs;
    string input;

    while(cin >> input)
        vs.push_back(input);
    elidups(vs);

    for(auto x : vs)
        cout << x << endl;
}

void elidups(vector<string>& vs)
{
    sort(vs.begin(), vs.end());
    auto dup = unique(vs.begin(), vs.end());
    vs.erase(dup, vs.end());
}
