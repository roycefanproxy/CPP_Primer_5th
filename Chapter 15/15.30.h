#ifndef _15_30_h_
#define _15_30_h_
#include <string>
#include <memory>
#include <set>
#include <memory>
#include <iostream>

class Quote;
double print_total(std::ostream&, const Quote&, size_t);

class Quote
{
	friend double print_total(std::ostream&, const Quote&, size_t);
public:
	Quote() = default;
	Quote(const std::string& s, const double& p) : b_name(s), price(p) {}
	Quote& operator=(const Quote& q)
	{
		b_name = q.b_name;
		price = q.price;
		return *this;
	}
	virtual ~Quote() = default;
	std::string name() const { return b_name; }
	virtual double net_price(size_t n) const { return price * n; }
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
protected:
	double price = 0.0;
private:
	std::string b_name;
};

class Bulk_Quote : public Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string& s, const double& p, size_t qty, const double& disc) : Quote(s, p), min_qty(qty), discount(disc) {}
	Bulk_Quote& operator=(const Bulk_Quote& bq)
	{
		Quote::operator=(bq);
		min_qty = bq.min_qty;
		discount = bq.discount;
		return *this;
	}
	~Bulk_Quote() = default;
	double net_price(size_t n) const override
	{
		return price * n * (n >= min_qty ? 1 - discount : 1);
	}
	Bulk_Quote* clone() const & override { return new Bulk_Quote(*this); }
	Bulk_Quote* clone() && override { return new Bulk_Quote(std::move(*this)); }
protected:
	size_t min_qty = 0;
	double discount = 0.0;
};

double print_total(std::ostream& os, const Quote& item, size_t n)
{
	double ret_val = item.net_price(n);
	os << "Book name : " << item.name() << " price : " << ret_val << std::endl;
	return ret_val;
}

struct Basket
{
	void add_item(const Quote& item) { container.insert(std::shared_ptr<Quote>(item.clone())); }
	void add_item(Quote&& item) { container.insert(std::shared_ptr<Quote>(std::move(item).clone())); }
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote>& ls, const std::shared_ptr<Quote>& rs) { return ls->name() < rs->name(); }
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> container{compare};
};

double Basket::total_receipt(std::ostream& os) const
{
	double ret_val = 0.0;

	for(auto itr = container.cbegin(); itr != container.cend(); itr = container.upper_bound(*itr))
		ret_val += print_total(os, **itr, container.count(*itr));
	return ret_val;
}

#endif // _15_30_h_

