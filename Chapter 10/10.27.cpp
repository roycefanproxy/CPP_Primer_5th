#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    vector<int> vi1;
    list<int> vi2;

    for(int i = 1; i <= 20; ++i)
        vi1.push_back(i);
    unique_copy(vi1.crbegin(), vi1.crend(), back_inserter(vi2));
    for(auto x : vi2)
        cout << x << endl;
}
