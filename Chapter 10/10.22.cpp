#include <iostream>
using namespace std;

int main()
{
    auto cs = [] (const string& s) { return s.size() <= 6; };
    string input;
    while(cin >> input)
        cout << (cs(input) ? "True." : "False.") << endl;

    return 0;
}
