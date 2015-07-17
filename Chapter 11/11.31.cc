#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    multimap<string, string> works;
    string author, book;
    while(getline(cin, author) && author != "done" && getline(cin, book))
        works.insert({author, book});
    cout << "Done.\n";
    cout << "Now insert author's name to delete his book(s)." << endl;
    for(auto& x : works)
        cout << x.first << ' ' << x.second << endl;
    cout << endl;
    while(getline(cin, author))
    {
        auto itr = works.find(author);
        auto count = works.count(author);
        if(!count)
            cout << "Author Not Found." << endl;
        while(count)
        {
            itr = works.erase(itr);
            --count;
        }
        cout << endl;
        for(auto& x : works)
            cout << x.first << ' ' << x.second << endl;
    }

    return 0;
}
