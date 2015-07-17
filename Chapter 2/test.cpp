#include <iostream>
#include <string>

using std::cin;
using std::endl;
using std::cout;

int main()
{
    std::string word;

    while(getline(cin, word))
    {
        if(!word.empty())
           cout << word << endl;
        else
            break;
    }

    return 0;
}
