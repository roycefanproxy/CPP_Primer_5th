#ifndef _15_3_h_
#define _15_3_h_
#include <iostream>
#include <string>

class Quote;

double print_total(std::ostream&, const Quote&, size_t);
class Quote
{
	friend double print_net(std::ostream&, const Quote&, size_t);
public:
	Quote() = default;
	Quote(const std::string&, const double&);
	std::string isbn() const;
	virtual double net_price(size_t) const;
	~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

Quote::Quote(const std::string& book, const double& sale_price) :
	bookNo(book), price(sale_price) {}

std::string Quote::isbn() const
{
	return bookNo;
}

double Quote::net_price(size_t n) const
{
	return price * n;
}

double print_total(std::ostream& os, const Quote& item, size_t n)
{
	auto ret_val = item.net_price(n);

	os << "ISBN : " << item.isbn()
	   << " # sold : " << n << " total due : " << ret_val << std::endl;
}

#endif // _15_3_h_
