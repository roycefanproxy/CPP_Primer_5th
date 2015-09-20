#ifndef _15_16_h_
#define _15_16_h_
#include "15.15.h"

class LD_Quote : public Disc_Quote
{
public:
	LD_Quote() = default;
	LD_Quote(const std::string& s, const double& sale_price, size_t qty, const double& disc)
		: Disc_Quote(s, sale_price, qty, disc) {}
	~LD_Quote() = default;
	double net_price(size_t n) const override
	{
		auto extra_price = n > min_qty ? price * (n - min_qty) : 0;
		return price * (n > min_qty ? min_qty : n) * (1 - discount) + extra_price;
	}
};

#endif // _15_16_h_
