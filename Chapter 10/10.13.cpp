#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check_size(const string&);

int main()
{
    vector<string> vs;
    string input;

    while(cin >> input)
        vs.push_back(input);

    vector<string>::const_iterator itr = partition(vs.begin(), vs.end(), check_size);
    for(auto b = vs.cbegin(); b != itr; ++b)
        cout << *b << endl;

    return 0;
}

bool check_size(const string& s) { return s.size() >= 5; }
