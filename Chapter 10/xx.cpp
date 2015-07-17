#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    istream_iterator<int> isii(cin), eof;
    vector<int> vi;
    ostream_iterator<int> osii(cout, " ");

    while(isii != eof)
        vi.push_back(*isii++);

    while(auto itr = vi.cbegin(); itr != vi.end(); ++itr)
        osii = *itr;
    cout << endl;

    return 0;
}

