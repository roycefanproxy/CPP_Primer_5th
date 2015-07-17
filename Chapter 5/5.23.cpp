#include <iostream>
#include <stdexcept>
#include <cctype>
using namespace std;
int main()
{
    double a, b;

    cout << "Enter two values." << endl;
    while(cin >> a)
    {
        try
        {
            cin >> b;
            if(b == 0)
                throw runtime_error("The divisor cannot be 0. Do you still want to continue the input?\nEnter 'N' to terminate the program otherwise reenter two values.");
            cout << a / b << endl;
        }
        catch(runtime_error re)
        {
            char input;
            cout << re.what() << endl;
            cin >> input;
            if(toupper(input) == 'N')
                break;
        }
    }


    return 0;
}
