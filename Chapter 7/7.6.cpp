#include <iostream>
#include <string>
using namespace std;

struct Sales_Data
{
    double avg_price() const { return unit_sold ? revenue / (int)unit_sold : 0; }
    string isbn() const { return book_no; }
    Sales_Data& combine(const Sales_Data&);

    double revenue = 0;
    string book_no;
    unsigned unit_sold = 0;
};

istream& read(istream&, Sales_Data&);
ostream& print(ostream&, const Sales_Data&);
Sales_Data add(const Sales_Data&, const Sales_Data&);

int main()
{
    Sales_Data curr, trans;

    if(read(cin, curr))
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
        cout << "No Books ?!" << endl;

    return 0;
}

Sales_Data add(const Sales_Data& ls, const Sales_Data& rs)
{
    Sales_Data newitem = ls;
    newitem.combine(rs);

    return newitem;
}

Sales_Data& Sales_Data::combine(const Sales_Data& item)
{
    revenue += item.revenue;
    unit_sold += item.unit_sold;

    return *this;
}

istream& read(istream& is, Sales_Data& item)
{
    double price = 0;
    is >> item.book_no >> item.unit_sold >> price;
    item.revenue = price * (int)item.unit_sold;

    return is;
}

ostream& print(ostream& os, const Sales_Data& item)
{
    cout << item.isbn() << " " << item.unit_sold << " " << item.avg_price() << endl;

    return os;
}
