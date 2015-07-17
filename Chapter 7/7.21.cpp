#include <iostream>
#include <string>
#include "S_D.h"

using namespace std;

int main(void)
{
    S_D curr(cin), trans;

    if(!curr.isbn().empty())
    {
        while(read(cin, trans))
        {
            if(curr.isbn() == trans.isbn())
                curr = add(curr, trans);
            else
            {
                print(cout, curr);
                curr = trans;
            }
        }
    }
    else
        cerr << "No book ? ! " << endl;

    cout << "Done." << endl;

    return 0;
}
