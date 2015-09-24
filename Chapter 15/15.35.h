#ifndef _15_35_h_
#define _15_35_h_
#include <string>
#include <memory>

class Query_Base
{
	friend class Query;
public:
	typedef size_t line_no;
	virtual ~Query_Base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

class Query
{
public:
	Query(const std::string& s);
	QueryResult eval(const TextQuery& tq) const { return q->eval(tq); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_Base> q) : query(q) {}
	std::shared_ptr<Query_Base> query;
};

#endif // _15_35_h_
