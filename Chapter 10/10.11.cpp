#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void elidups(vector<string>&);
bool isShorter(const string&, const string&);
int main()
{
    vector<string> vs;
    string input;

    while(cin >> input)
        vs.push_back(input);
    elidups(vs);
    stable_sort(vs.begin(), vs.end(), isShorter);

    for(auto x : vs)
        cout << x << endl;

    return 0;

}

void elidups(vector<string>& vs)
{
    sort(vs.begin(), vs.end());
    auto x = unique(vs.begin(), vs.end());
    vs.erase(x, vs.end());
}

bool isShorter(const string& a, const string& b) { return a.size() < b.size(); }
