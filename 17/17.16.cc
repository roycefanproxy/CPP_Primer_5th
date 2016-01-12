#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    regex rule("[^c]ei");
    smatch result;

    string input;

    while(cin >> input && input != "q")
    {
        if(regex_search(input, result, rule))
            cout << "Boom!" << endl;
        else
            cout << "Fine." << endl;
    }

    return 0;
}

