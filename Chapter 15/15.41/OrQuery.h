#ifndef _OrQuery_h_
#define _OrQuery_h_
#include <string>
#include "Query.h"
#include "BinaryQuery.h"
#include "TextQuery.h"

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
private:
	OrQuery(const Query& ls, const Query& rs) : BinaryQuery(ls, rs, "|") {}
	QueryResult eval(const TextQuery&) const override;
};

QueryResult OrQuery::eval(const TextQuery& tq) const
{
	auto ls = lhs.eval(tq), rs = rhs.eval(tq);
	auto result = new std::set<line_no>(ls.begin(), ls.end());
	result->insert(rs.begin(), rs.end());
	return {rep(), ls.get_file(), result};
}

inline Query operator|(const Query& ls, const Query& rs)
{
	return new OrQuery(ls, rs);
}

#endif // _OrQuery_h_

