#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string prev(""), curr;
    bool flag = false;
    while(cin >> curr)
    {
        if(isupper(curr[0]))
        {
            if(curr == prev)
            {
                flag = true;
                break;
            }
            else
            {
                prev = curr;
                continue;
            }
        }
        prev = "";
    }

    if(flag)
        cout << curr << " repeated." << endl;
    else
        cout << "No word occurred twice." << endl;

    return 0;
}
