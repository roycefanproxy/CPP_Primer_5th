#include <iostream>
#include "Sales_Data.h"
using namespace std;

ostream& print(ostream&, const Sales_Data&);
istream& read(istream&, Sales_Data&);

int main(void)
{
    Sales_Data test;

    read(cin, test);
    print(cout, test);
    return 0;
}

ostream &print(std::ostream &os, const Sales_Data& sd)
{
    return (os << sd.isbn() << " " << sd.unit_sold << " " << sd.revenue << " " << sd.avg_price() << endl);
}

istream &read(std::istream &is, Sales_Data& sd)
{
    double price = 0;

    is >> sd.book_no >> sd.unit_sold >> price;
    sd.revenue = price * sd.unit_sold;

    return is;
}
