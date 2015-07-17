#include <iostream>
#include <forward_list>
#include <list>
using namespace std;

int main()
{
    forward_list<int> container{1,2,3,4,5,6,7,8,9,10};
    list<int> c2(container.begin(), container.end());
{

    auto curr = container.begin(), prev = container.before_begin();
    while(curr != container.end())
    {
        if(*curr % 2)
        {
            curr = container.insert_after(curr, *curr);
            prev = curr++;
        }
        else
        {
            curr = container.erase_after(prev);
        }
    }
}
    auto curr = c2.begin();
    while(curr != c2.end())
    {
        if(*curr % 2)
        {
            curr = c2.insert(curr, *curr);
            ++curr;
            ++curr;
        }
        else
            curr = c2.erase(curr);
    }

    for(auto x : container)
        cout << x << endl;
    cout << endl;

    for(auto x : c2)
        cout << x << endl;
    cout << endl;
    return 0;
}
