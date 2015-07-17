#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> li{235,2523,454,3,61,613,72,46,7,25,45431,0,7};

    auto result = find(li.crbegin(), li.crend(), 0);
    cout << distance(li.cbegin(), result.base()) << ' ' << *result << endl;
}
