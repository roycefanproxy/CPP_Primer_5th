#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{
    int size;
    string input;
    allocator<string> alloc;

    cout << "Enter the size of array : " << flush;
    cin >> size;

    string * const p = alloc.allocate(size);
    string * q = p;

    while(cin >> input && q != p + size)
        alloc.construct(q++, input);
    while(q != p)
    {
        cout << *--q << endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, size);

    return 0;
}
