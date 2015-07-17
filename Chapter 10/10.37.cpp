#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> li;

    copy(vi.cbegin() + 3, vi.cbegin() + 8, front_inserter(li));
    for(auto x : li)
        cout << x << endl;
}
