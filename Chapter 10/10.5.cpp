#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> v1;
    list<string> v2;
    char temp[20];

    for(int i = 0; i != 10; ++i)
    {
        sprintf(temp, "No.%d", i + 1);
        v1.push_back(temp);
        v2.push_back(temp);
    }
    auto x = equal(v1.cbegin(), v1.cend(), v2.cbegin());
    cout << x << endl;
}
