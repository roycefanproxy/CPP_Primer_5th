#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<string> box;
    string curr, prev("");
    bool flag = true;

    while(cin >> curr)
    {
        if(curr == prev)
        {
            flag = false;
            break;
        }
        else
            prev = curr;
    }
    if(flag)
        cout << "No word repeated." << endl;
    else
        cout << curr << " occurred twice." << endl;

    return 0;
}
