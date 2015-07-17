#include <fstream>
#include <string>
#include <vector>
#include "Sales_Data.h"

using namespace std;


int main(void)
{
    Sales_Data curr, trans;
    string filename;
    cout << "Enter filename." << endl;
    cin >> filename;
    ifstream file("file1.txt");
    if(file)
        if(read(file, curr))
        {
            read(file, trans);
            if(curr.bookNo == trans.bookNo)
            {
                curr.revenue += trans.revenue;
                curr.unit_sold += trans.unit_sold;
            }
            else
            {
                print(cout, curr);
                curr = trans;
            }
        }

    file.close();

    return 0;
}

