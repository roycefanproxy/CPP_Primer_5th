#include <iostream>
#include <vector>
#include <algorithm>
#include "S_D.h"
#include <string>
using namespace std;

int main(void)
{
    vector<S_D> vsd;
    S_D input;

    while(read(cin, input))
        vsd.push_back(input);

    sort(vsd.begin(), vsd.end(), [](const S_D& a, const S_D& b) { return a.isbn() < b.isbn(); });
    for(auto x : vsd)
        print(cout, x);

    return 0;
}
