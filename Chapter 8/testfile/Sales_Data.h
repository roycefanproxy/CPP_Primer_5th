#ifndef _Sales_Data_h_
#define _Sales_Data_h_
#include <iostream>


struct Sales_Data
{
    std::string bookNo;
    unsigned unit_sold;
    double revenue;
};

std::istream& read(std::istream& is, Sales_Data item)
{
    is >> item.bookNo >> item.unit_sold >> item.revenue;

    return is;
}

std::ostream& print(std::ostream& os, const Sales_Data item)
{
    os << item.bookNo << " " << item.unit_sold << " " << (item.revenue / item.unit_sold) << std::endl;

    return os;
}
#endif // _Sales_Data_h_
