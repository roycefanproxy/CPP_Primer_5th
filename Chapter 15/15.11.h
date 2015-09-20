#ifndef _15_11_h_
#define _15_11_h_
#define DEBUG
#include <iostream>
#include <string>

class Quote;
double print_total(std::ostream&, const Quote&, size_t);

class Quote
{
	friend double print_total(std::ostream&, const Quote&, size_t);
public:
	Quote() = default;
	Quote(const std::string& s, const double& sale_price) : bookNo(s), price(sale_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return price * n; }
	virtual std::ostream& debug(std::ostream& os = std::cout) const
	{
		return os << bookNo << ' ' << price;
	}
protected:
	double price = 0.0;
private:
	std::string bookNo;
};

double print_total(std::ostream& os, const Quote& item, size_t n)
{
	auto ret_val = item.net_price(n);
	os << "Book : " << item.isbn() << " # sold : " << n << " price due : " << ret_val << std::endl;
#ifdef DEBUG
	item.debug() << std::endl;
#endif // DEBUG
	return ret_val;
}

class Bulk_Quote : public Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string& s, const double& sale_price, size_t qty, const double& disc)
		: Quote(s, sale_price), min_qty(qty), discount(disc) {}
	double net_price(size_t n) const override
	{
		return price * n * (n >= min_qty ? 1 - discount : 1);
	}

	std::ostream& debug(std::ostream& os = std::cout) const override
	{
		return Quote::debug() << ' ' << min_qty << ' ' << discount * 100 << '%';
	}
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

#endif // _15_11_h_
