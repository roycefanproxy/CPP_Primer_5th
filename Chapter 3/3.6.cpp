#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string x;
    while(getline(cin, x))
    {
        for(char& c : x)
            c = toupper(c);
        cout << x << endl;
    }

    return 0;
}
