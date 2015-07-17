#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<int> ptr(new int(5));
    weak_ptr<int> wptr(ptr);

    if(int x = 5)
        cout << "Locked." << endl;
}
