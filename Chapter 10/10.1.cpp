#include <iostream>
#include <algorithm>
#include <vector>
using std::vector; using std::cout; using std::endl;
int main()
{
    vector<int> vi;
    for(int i = 0; i != 11; ++i)
        vi.push_back(i);
    vi.push_back(5);

    auto x = std::count(vi.cbegin(), vi.cend(), 5);

    cout << x << endl;

    return 0;
}
