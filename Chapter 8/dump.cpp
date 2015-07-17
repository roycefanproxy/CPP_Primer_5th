#include <deque>
#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    deque<int> storage;
    for(int i = 0; i < 5; ++i)
    {
        storage.emplace_back(i + 1);
    }
    for(auto x : storage)
        cout << x << endl;
    return 0;
}
