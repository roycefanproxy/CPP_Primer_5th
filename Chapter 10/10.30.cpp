#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    istream_iterator<int> isii(cin), eof;
    vector<int> vi;
    ostream_iterator<int> osii(cout, " ");

    while(isii != eof)
        vi.push_back(*isii++);

    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), osii);
    cout << endl;

    return 0;
}
