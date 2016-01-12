#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    regex rule("[[:alpha:]]*[^c]ei[[:alpha:]]*");

    string input;

    smatch result;

    while(cin >> input && input != "q")
    {
        if(!regex_search(input, result, rule))
        {
            cout << "The input " << result.str() << " is valid." << endl;
        }
        else
        {
            cout << result.str() << " is invalid input." << endl;
        }
    }

    return 0;
}
