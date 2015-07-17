#ifndef _S_D_
#define _S_D_
#include <iostream>

class S_D
{
    friend S_D add(const S_D&, const S_D&);
    friend std::istream& read(std::istream&, S_D&);
    friend std::ostream& print(std::ostream& os, const S_D& item);
public:
    S_D() = default;
    S_D(std::istream& is) { read(is, *this); }
    S_D(std::string isbn, unsigned quantity, double revenue) : book_no(isbn), unit_sold(quantity), revenue(this->revenue) {}
    std::string isbn() const { return book_no; }
    S_D& combine(const S_D&);

private:
    double avg_price() const { return unit_sold ? revenue / (int) unit_sold : 0; }

    std::string book_no;
    double revenue = 0;
    unsigned unit_sold = 0;

};

S_D& S_D::combine(const S_D& item)
{
    this->revenue += item.revenue;
    this->unit_sold += item.unit_sold;

    return *this;
}

S_D add(const S_D& a, const S_D& b)
{
    S_D temp = a;
    temp.combine(b);

    return temp;
}

std::istream& read(std::istream& is, S_D& item)
{
    double price = 0;
    is >> item.book_no >> item.unit_sold >> price;
    item.revenue = price * (int)item.unit_sold;

    return is;
}

std::ostream& print(std::ostream& os, const S_D& item)
{
    os << item.isbn() << " " << item.unit_sold << " " << item.avg_price() << std::endl;

    return os;
}

#endif // _S_D_
