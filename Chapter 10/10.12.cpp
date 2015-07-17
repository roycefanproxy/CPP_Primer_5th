#include "S_D.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compareISBN(const S_D&, const S_D&);

int main()
{
    vector<S_D> vsd;
    S_D input;
    while(read(cin, input))
        vsd.push_back(input);
    sort(vsd.begin(), vsd.end(), compareISBN);

    for(auto& x : vsd)
        print(cout, x);

    return 0;
}

bool compareISBN(const S_D& a, const S_D& b) { return a.isbn() < b.isbn(); }
