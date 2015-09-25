#ifndef _Query_h_
#define _Query_h_
#include "TextQuery.h"

class Query
{
public:
	Query(const std::string& s);
	QueryResult eval(const TextQuery& tq) const { return query->eval(tq); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_Base> q) : query(q) {}
	std::shared_ptr<Query_Base> query;
};

class Query_Base
{
	friend class Query;
public:
	typedef TextQuery::line_no line_no;
	virtual ~Query_Base() = default;
private:
	virtual QueryResult eval(const TextQuery& tq) const = 0;
	virtual std::string rep() const = 0;
};

#endif // _Query_h_

