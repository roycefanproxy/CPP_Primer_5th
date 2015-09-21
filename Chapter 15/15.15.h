#ifndef  _15_15_h_
#define _15_15_h_
#include <iostream>
#include <string>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string& s, const double& sale_price) : bookNo(s), price(sale_price) {}
	virtual ~Quote() = default;
	std::string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return price * n; }
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Disc_Quote : public Quote
{
public:
	Disc_Quote() = default;
	Disc_Quote(const std::string& s, const double& sale_price, size_t qty, const double& disc)
		: Quote(s, sale_price), min_qty(qty), discount(disc) {}
	~Disc_Quote() = default;
	virtual double net_price(size_t n) const override = 0;
protected:
	double discount = 0.0;
	size_t min_qty = 0;
};

class Bulk_Quote : public Disc_Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string& s, const double& sale_price, size_t qty, const double& disc)
		: Disc_Quote(s, sale_price, qty, disc) {}
	~Bulk_Quote() = default;
	double net_price(size_t n) const override
	{
		return price * n * (n > min_qty ? 1 - discount : 1);
	}
};

#endif // _15_15_h_
