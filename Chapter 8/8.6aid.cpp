#include <iostream>
#include <fstream>
#include <vector>
#include "Sales_Data.h"

using namespace std;

int main(void)
{
    Sales_Data buff;
    ofstream file("file1.txt");
    if(file)
    {
        while(cin >> buff.bookNo)
        {
            cin >> buff.unit_sold >> buff.revenue;
            file << " " << buff.bookNo << " " << buff.unit_sold << " " << buff.revenue;
        }
        file.close();
    }
    cout << "Done." << endl;

    return 0;


}
