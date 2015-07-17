#include <iostream>
#include <string>
using std::cin; using std::cout; using std::string;

struct Sales_D;

std::istream& read(std::istream&, Sales_D&);
std::ostream& print(std::ostream&, const Sales_D&);
Sales_D add(const Sales_D&, const Sales_D&);

struct Sales_D
{
    string book_no;
    unsigned unit_sold = 0;
    double revenue;

    Sales_D() : revenue(0) {}
    Sales_D(std::istream& s) : revenue(0) { read(s, *this); }
    Sales_D(const string isbn, const unsigned unit, const double price) : book_no(isbn), unit_sold(unit), revenue(price * (int) unit_sold) {}

    string isbn() const { return book_no; }
    Sales_D& combine(const Sales_D item)
    {
        this->unit_sold += item.unit_sold;
        this->revenue += item.revenue;

        return *this;
    }
    double avg_price(void) const;
};

double Sales_D::avg_price(void) const { return unit_sold ? revenue / (int) unit_sold : 0; }

int main(void)
{
    Sales_D curr(cin), trans;

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
        std::cerr << "Empty ?!" << std::endl;

    return 0;
}

std::istream& read(std::istream& is, Sales_D& item)
{
    double price = 0;

    is >> item.book_no >> item.unit_sold >> price;
    item.revenue = price * item.unit_sold;

    return is;
}

std::ostream& print(std::ostream& os, const Sales_D& item)
{
    os << item.isbn() << " " << item.unit_sold << " " << item.avg_price() << std::endl;

    return os;
}

Sales_D add(const Sales_D& a, const Sales_D& b)
{
    Sales_D temp = a;

    temp.combine(b);

    return temp;
}
