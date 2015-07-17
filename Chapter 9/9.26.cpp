#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    auto b = begin(arr), e = end(arr);
    vector<int> v(b, e);
    list<int> l(b, e);

    auto vb = v.begin();
    auto lb = l.begin();
    while(vb != v.end() || lb != l.end())
    {
        if(vb == v.end()) ;
        else if(*vb % 2 != 1)
            vb = v.erase(vb);
        else
            ++vb;
        if(lb == l.end()) ;
        else if(*lb % 2)
            lb = l.erase(lb);
        else
            ++lb;

    }

    cout << "vector : even values." << endl;
    for(auto x : v)
        cout << x << ends;
    cout << '\n' << "list : odd values." << endl;
    for(auto x : l)
        cout << x << ends;

    return 0;
}
