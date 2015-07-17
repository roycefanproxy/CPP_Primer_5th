#include <iostream>
#include <cctype>
using namespace std;

bool isUpper(const string&);
bool toUpper(string&);

int main(void)
{
    string input;

    while(getline(cin, input))
    {
        cout << (isUpper(input) ? "True" : "False") << endl;
        toUpper(input);
        cout << "ToUpper Result :\n" << input << endl;
    }

    return 0;
}

bool isUpper(const string &s)
{
    bool flag = false;
    for(char c : s)
        if(isupper(c))
        {
            flag = true;
            break;
        }

    return flag;
}

bool toUpper(string &s)
{
    auto ssize = s.size();
    for(decltype(ssize) i = 0; i != ssize; ++i)
        s[i] = toupper(s[i]);

    return true;
}
