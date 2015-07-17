#include <iostream>
#include <functional>
#include <vector>
using namespace std;
using namespace placeholders;

bool check_size(const string&, int&);

int main()
{
    vector<int> vi(1);
    string input;
    auto te = bind(check_size, _1, ref(vi[0]));

    while(cin >> vi[0])
    {
        cin >> input;
        cout << (te(input) ? "True" : "False") << '.' << endl;
    }

    return 0;
}

bool check_size(const string& s, int& sz)
{
    return s.size() <= sz;
}
