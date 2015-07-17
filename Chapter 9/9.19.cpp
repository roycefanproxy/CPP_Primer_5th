#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<string> container;
    string input;

    while(cin >> input)
        container.emplace_back(input);

    for(auto x = container.cbegin(), y = container.cend(); x != y; ++x)
        cout << *x << endl;

    return 0;
}
