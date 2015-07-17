#include <vector>
#include <list>
#include "S_D.h"
using namespace std;

int main(void)
{
    list<S_D> the_l(20, {"test"});
    vector<S_D> try_v(the_l.cbegin(), the_l.cend());

    cout << try_v[0].isbn() << endl;
}
