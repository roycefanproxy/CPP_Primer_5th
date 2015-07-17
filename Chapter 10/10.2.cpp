#include <iostream>
#include <list>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    list<string> ls;
    char temp[20];
    for(int i = 0; i != 10; ++i)
    {
        sprintf(temp, "No. %d", i + 1);
        ls.push_back(temp);
    }
    ls.push_back("No. 5");

    cout << count(ls.cbegin(), ls.cend(), "No. 5") << endl;
}
