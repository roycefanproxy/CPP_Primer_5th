#include <iostream>
#include <list>
using namespace std;

void elimdups(list<string>&);

int main()
{
    list<string> ls;
    string input;
    while(cin >> input)
        ls.push_back(input);
    elimdups(ls);
    for(auto x : ls)
        cout << x << endl;

    return 0;
}

void elimdups(list<string>& ls)
{
    ls.sort();
    ls.unique();
}


