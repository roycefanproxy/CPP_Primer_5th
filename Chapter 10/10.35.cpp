#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vi;
    for(int i = 1; i != 21; ++i)
        vi.push_back(i);
    for(auto itr = --vi.cend(); itr != vi.cbegin() - 1; itr--)
        cout << *itr << endl;
}
