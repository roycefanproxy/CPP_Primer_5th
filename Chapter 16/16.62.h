#ifndef _16_62_H_
#define _16_62_H_
#include <iostream>
#include <string>
#include <functional>

class Sales_Data;


std::ostream& operator<<(std::ostream&, const Sales_Data&);
std::istream& operator>>(std::istream&, Sales_Data&);

bool operator==(const Sales_Data&, const Sales_Data&);

class Sales_Data
{
    friend std::istream& operator>>(std::istream&, Sales_Data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_Data&);
    friend class std::hash<Sales_Data>;
public:
    std::string isbn() const { return name; }

private:
    std::string name;
    unsigned unit_sold;
    double revenue;
};

std::ostream& operator<<(std::ostream& os, const Sales_Data& item)
{
    return os << item.isbn() << ' ' << item.unit_sold << ' ' << item.revenue;
}

std::istream& operator>>(std::istream& is, Sales_Data& item)
{
    double price;
    is >> item.name >> item.unit_sold >> price;
    item.revenue = price * item.unit_sold;
    return is;
}

bool operator==(const Sales_Data& lhs, const Sales_Data& rhs)
{
    return lhs.isbn() == rhs.isbn();
}

namespace std
{
    template<> class hash<Sales_Data>
    {
    public:
        typedef size_t result_type;
        typedef Sales_Data argument_type;

        size_t operator()(const Sales_Data&) const;
    };

    size_t hash<Sales_Data>::operator()(const Sales_Data& item) const
    {
        return hash<string>()(item.isbn()) ^
               hash<unsigned>()(item.unit_sold) ^
               hash<double>()(item.revenue);
    }
}

#endif // _16_62_H_
