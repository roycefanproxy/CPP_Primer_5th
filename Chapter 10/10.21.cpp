#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;
    int resp;
    auto func = [&] (void) -> bool { if(input) { --input; return true; } else return false; };
    while((cin >> resp) && resp)
    {
        if(func())
            cout << input << endl;
        else
            cout << "input is " << input << endl;
    }

    return 0;
}
