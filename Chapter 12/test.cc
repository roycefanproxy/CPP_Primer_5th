#include <memory>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int *test(new int[20]);
    for(auto x = 0; x != 20; ++x)
        test[x] = 0;
    for(auto x = 0; x != 20; ++x)
        cout << test[x] << endl;
}
