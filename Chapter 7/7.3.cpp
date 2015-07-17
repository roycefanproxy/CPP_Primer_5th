#include <iostream>
#include <string>
#include "Sales_Data.h"
using namespace std;

int main()
{
    Sales_Data curr, trans;
    double price = 0;
    if(cin >> curr.book_no >> curr.unit_sold >> price)
    {
        curr.revenue = price * (int)curr.unit_sold;
        cout << curr.revenue << endl;
        while(cin >> trans.book_no >> trans.unit_sold >> price)
        {
            price = 0;
            trans.revenue = price * (int)trans.unit_sold;
            if(curr.isbn() != trans.isbn())
            {
                cout << curr.isbn() << " " << curr.unit_sold << " " << curr.revenue / (int)curr.unit_sold << endl;
                curr = trans;
            }
            else
                curr.combine(trans);
        }
    }

    cout << "Done." << endl;

    return 0;
}
