#ifndef _13_5_h_
#define _13_5_h_
#include <iostream>
#include <string>

class Quote;
class Bulk_Quote;

double print_total(std::ostream&, const Quote&, size_t);

class Quote
{
	friend double print_total(std::ostream&, const Quote&, size_t);
public:
	Quote() = default;
	Quote(const std::string& book, const double& sale_price) :
		bookNo(book), price(sale_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(size_t n ) const { return price * n; }
protected:
	double price = 0.0;
private:
	std::string bookNo;
};

class Bulk_Quote : public Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string& book, const double& sale_price, size_t dis_qty, const double& disc) 		: Quote(book, sale_price), min_qty(dis_qty), discount(disc) {}
	double net_price(size_t) const override final;
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

double Bulk_Quote::net_price(size_t n) const
{
	return price * n * (n >= min_qty ? 1 - discount : 1);
}

double print_total(std::ostream& os, const Quote& item, size_t n)
{
	auto ret_val = item.net_price(n);
	os << "ISBN : " << item.isbn() << " # sold : " << n
	   << " total due : " << ret_val << std::endl;
	
	return ret_val;
}


#endif // _15_5_h_

