#ifndef _15_26_h_
#define _15_26_h_
#include <string>
#include <iostream>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string& s, const double& p) : bookNo(s), price(p) {}
	Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) { std::cout << "Quote copy constructor running." << std::endl; }
	Quote& operator=(const Quote& q) 
	{
		bookNo = q.bookNo;
		std::cout << "Quote assignment operator running." << std::endl;
		price = q.price;
		return *this;
	}
	~Quote() { std::cout << "Quote destructor executing." << std::endl; }
	std::string name() const { return bookNo; }
	virtual double net_price(size_t n) const { return price * n; }
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_Quote : public Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string& s, const double& p, const size_t& qty, const double& disc)
		: Quote(s, p), min_qty(qty), discount(disc) {}
	Bulk_Quote(const Bulk_Quote& bq) : Quote(bq), min_qty(bq.min_qty), discount(bq.discount)
	{
		std::cout << "Bulk_Quote copy constructor running." << std::endl;
	}
	Bulk_Quote& operator=(const Bulk_Quote& bq)
	{
		Quote::operator=(bq);
		min_qty = bq.min_qty;
		std::cout << "Bulk_Quote assignment operator is executing." << std::endl;
		discount = bq.discount;
		return *this;
	}
	~Bulk_Quote() { std::cout << "Bulk_Quote destructor running." << std::endl; }
	double net_price(size_t n) const override
	{
		return price * n * (n >= min_qty ? 1 - discount : 1);
	}
private:
	double discount = 0.0;
	size_t min_qty = 0;
};

#endif // _15_26_h_


