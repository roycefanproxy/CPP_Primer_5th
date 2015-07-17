#include <iostream>
#include <vector>
using namespace std;
typedef vector<string>::const_iterator CITOR;

void print(CITOR, CITOR);

int main()
{
    vector<string> box;
    string temp;

    while(cin >> temp)
        box.push_back(temp);

    print(box.cbegin(), box.cend());

    return 0;
}

void print(CITOR cur, decltype(cur) endp)
{
    if(cur != endp)
    {
        cout << *cur << ' ';
        print(next(cur), endp);
    }
    else
        cout << endl;
}
