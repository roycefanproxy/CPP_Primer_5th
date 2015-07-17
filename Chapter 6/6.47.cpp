#include <iostream>
#include <vector>
//#define NDEBUG
#include <cassert>

using namespace std;

void print(vector<string>&, vector<string>::const_iterator);

int main()
{
    string input;
    vector<string> locker;
    while(cin >> input)
    {
        locker.push_back(input);
        print(locker, locker.cbegin());
    }

    return 0;
}

void print(vector<string>& l, vector<string>::const_iterator itor)
{
    assert(itor < l.cend());
#ifndef NDEBUG
    cout << "times : " << itor - l.cbegin() + 1 << endl;
#endif // NDEBUG
    cout << *itor << endl;
    if(++itor != l.cend())
        print(l, itor);
}
