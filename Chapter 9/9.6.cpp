#include <iostream>
#include <forward_list>
using namespace std;

int main(void)
{
    forward_list<int> the_l(3, 0);
    auto b = the_l.begin(), e = the_l.end();
    while(b != e)
    {
        cout << *b << endl;
        ++b;
    }

    return 0;

}
