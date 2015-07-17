#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    ostream_iterator<int> osi(cout, " ");
    istream_iterator<int> isi(cin), eof;
    vector<int> vi;

    while(isi != eof)
        vi.push_back(*isi++);
    sort(vi.begin(), vi.end());
    unique_copy(vi.cbegin(), vi.cend(), osi);
    cout << endl;

    return 0;
}
