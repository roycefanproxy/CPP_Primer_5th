#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

void the_func(forward_list<string>&, const string, const string);

int main(void)
{
    forward_list<string> container;
    string checker, input;
    while(cin >> checker)
    {
        cin >> input;
        the_func(container, checker, input);
    }

    for(auto&x : container)
        cout << x << endl;

    return 0;

}

void the_func(forward_list<string>& fl, const string c, const string input)
{
    auto prev = fl.before_begin(), cur = fl.begin();
    while(cur != fl.end())
    {
        if(*cur == c)
        {
            fl.insert_after(cur, input);
            return;
        }
        prev = cur++;
    }
    fl.insert_after(prev, input);
}
