#ifndef _17_4_H_
#define _17_4_H_
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>

class Sales_Data
{
    friend Sales_Data operator+(const Sales_Data&, const Sales_Data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_Data&);
public:
    Sales_Data(const std::string& name, const unsigned& u_s, const double& price)
        : bookNo(name), unit_sold(u_s), revenue(price * u_s) {}
    std::string isbn() const { return bookNo; }
private:
    std::string bookNo;
    unsigned unit_sold;
    double revenue;
};

std::ostream& operator<<(std::ostream& os, const Sales_Data& sd)
{
    return os << sd.isbn() << ' ' << sd.unit_sold << ' ' << sd.revenue;
}

Sales_Data operator+(const Sales_Data& lhs, const Sales_Data& rhs)
{
    return Sales_Data(lhs.isbn(), lhs.unit_sold + rhs.unit_sold, lhs.revenue + rhs.revenue);
}

bool operator<(const Sales_Data& lhs, const Sales_Data& rhs)
{
    return lhs.isbn() < rhs.isbn();
}

typedef std::tuple<std::vector<Sales_Data>::size_type,
                   std::vector<Sales_Data>::const_iterator,
                   std::vector<Sales_Data>::const_iterator> matches;

std::vector<matches> FindBook(const std::vector<std::vector<Sales_Data>>& stores, const std::string& name)
{
    std::vector<matches> ret;
    
    for(auto itr = stores.cbegin(); itr != stores.cend(); ++itr)
    {
        // the data from each stores must be sorted.
        auto found = std::equal_range(itr->cbegin(), itr->cend(), Sales_Data(name, 0, 0));
        if(found.first != found.second)
            ret.push_back(std::make_tuple(itr - stores.cbegin(), found.first, found.second));
    }

    return ret;
}


void ReportResults(std::istream& is, std::ostream& os, const std::vector<std::vector<Sales_Data>>& stores)
{
    std::string book_name;
    while(is >> book_name && book_name != "q")
    {
        auto result = FindBook(stores, book_name);
        if(result.empty())
        {
            std::cout << "The book \"" << book_name << "\" not found in any store." << std::endl;
        }
        else
        {
            for(const auto& store : result)
            {
                os << "Store " << std::get<0>(store) << " sales : " << std::accumulate(std::get<1>(store), std::get<2>(store), Sales_Data(book_name, 0, 0)) << std::endl;
            }
        }
    }
}

#endif // _17_4_H_
