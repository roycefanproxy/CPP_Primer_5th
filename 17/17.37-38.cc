#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("17.11.h");

    char line[200];
    while(file.getline(line, 200))
        cout << line << '\n';
    cout << endl;

    return 0;
}
