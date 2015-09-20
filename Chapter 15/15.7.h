#ifndef _15_7_h_
#define _15_7_h_
#include "15.5.h"

class LD_Quote : public Quote
{
public:
	LD_Quote() = default;
	LD_Quote(const std::string& book, const double& sale_price, size_t q, const double& disc)
		: Quote(book, sale_price), max_qty(q), discount(disc) {}
	double net_price(size_t n) const override;
private:
	size_t max_qty = 0;
	double discount = 0.0;
};

double LD_Quote::net_price(size_t n) const
{
	double extra = n > max_qty ? price * (n - max_qty) : 0;
	return price * (extra ? max_qty : n) * (1 - discount) + extra;
}

#endif // _15_7_h_
