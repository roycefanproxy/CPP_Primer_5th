#include "TextQuery.h"
using namespace std;

void ReadQuery(istream& is);

int main()
{
    ifstream file("TextQuery.h");

    if(file.is_open())
        ReadQuery(file);

    file.close();

    return 0;
}

void ReadQuery(istream& is)
{
    string input;
    TextQuery tq(is);

    cout << "The word you search for : ";
    while(1)
    {
        if(!(cin >> input) || input == "q") break;
        print(cout, tq.query(input)) << endl;
    }
}
