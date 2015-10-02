#ifndef _Query_h_
#define _Query_h_
#include <string>
#include <memory>
#include <iostream>
#include "TextQuery.h"
#include "Query_Base.h"
#include "WordQuery.h"

class Query
{
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	Query(const std::string& s) : query(new WordQuery(s)) {}
	QueryResult eval(const TextQuery& tq) const { return query->eval(tq); }
	std::string rep() const { return query->rep(); }
private:
	Query(std::shared_ptr<Query_Base> q) : query(q) {}
	std::shared_ptr<Query_Base> query;
};

std::ostream& operator<<(const std::ostream& os, const Query& q)
{
	return os << q.rep();
}

#endif // _Query_h_

