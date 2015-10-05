#ifndef _QUERY_H_
#define _QUERY_H_
#include <memory>
#include <string>
#include "TextQuery.h"
#include "Query_Base.h"
#include "WordQuery.h"

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	using line_no = TextQuery::line_no;
	Query(const std::string& s) : query(new WordQuery(s)) {}
	std::string rep() const { return query->rep(); }
	QueryResult eval(const TextQuery& tq) const { return query->eval(tq); }
private:
	Query(std::shared_ptr<Query_Base> q) : query(q) {}
	std::shared_ptr<Query_Base> query;
};

#endif // _QUERY_H_
