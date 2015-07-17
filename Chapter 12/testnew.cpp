#include <iostream>
#include <new>
#include <memory>
#include <vector>
using namespace std;

int main()
{
    auto ptr = new vector<int>(initializer_list<int>{1,2,3,4,5});

    cout << (*ptr)[0] << endl;

    delete ptr;
}
