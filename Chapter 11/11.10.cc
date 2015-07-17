#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

int main()
{
    map<vector<int>::iterator, int> mvii;
    map<list<int>::iterator, int> mlii;
    list<int> li;
    vector<int> vi;

    for(int i = 0; i != 20; ++i)
    {
        vi.push_back(i + 1);
        li.push_back(i + 1);
    }

    for(int i = 0; i != 2; ++i)
    {
        for(auto x = vi.begin(); x != vi.end(); ++x)
            mvii[x]++;
        /*for(auto y = li.begin(); y != li.end(); ++y)
            mlii[y]++;*/
    }

    for(auto& x : mvii)
        cout << *x.first << ' ' << x.second << endl;
    cout << endl;
   // for(auto& y : mlii)
   //     cout << *y.first << ' ' << y.second << endl;



}
