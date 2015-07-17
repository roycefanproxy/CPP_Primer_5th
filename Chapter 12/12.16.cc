#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> ptr(new int(5));
    auto ptr2(ptr.release());
    cout << *ptr2 << endl;
}
