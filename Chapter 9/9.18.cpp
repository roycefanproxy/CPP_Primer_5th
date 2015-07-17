#include <iostream>
#include <deque>
using namespace std;

int main()
{
    string input;
    deque<string> container;

    while(cin >> input)
        container.push_back(input);

    for(auto x = container.cbegin(), y = container.cend(); x != y; ++x)
        cout << *x << endl;

    return 0;
}
