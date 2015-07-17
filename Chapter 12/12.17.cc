#include <memory>
#include <iostream>
using namespace std;
typedef unique_ptr<int> IntP;

int* func(int* x)
{
    IntP ptr(x);
    IntP e(new int(5));

    cout << *e << endl;
    return e.get();


}

int main()
{
    int x = 20;
    auto y = func(&x);

    cout << *y << endl;
}
