#ifndef _Sales_Data_
#include <iostream>
#define _Sales_Data_

struct Sales_Data
{
    std::string isbn() const { return book_no; }
    Sales_Data& combine(const Sales_Data&);
    double avg_price() const
    {
        if(unit_sold)
            return revenue / unit_sold;

        return 0;
    }

    std::string book_no;
    unsigned unit_sold = 0;
    double revenue = 0;


};

Sales_Data& Sales_Data::combine(const Sales_Data& sd)
{
    revenue += sd.revenue;
    unit_sold += sd.unit_sold;

    return *this;
}

#endif // _Sales_Data_
