#include <memory>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> test = {"one", "two"};
    const auto test2(test);
    cout << test.back();
    test.pop_back();
    cout << ' ' << test.back() << endl;
    test.pop_back();
    cout << test2.front();
    cout << ' ' << test2.front() << endl;

    return 0;
}
