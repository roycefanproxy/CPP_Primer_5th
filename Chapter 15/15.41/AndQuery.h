#ifndef _AndQuery_h_
#define _AndQuery_h_
#include <string>
#include <algorithm>
#include <iterator>
#include "BinaryQuery.h"
#include "Query.h"
#include "TextQuery.h"

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query& ls, const Query& rs) : BinaryQuery(ls, rs, "&") {}
	QueryResult eval(const TextQuery&) const override;
};

QueryResult AndQuery::eval(const TextQuery& tq) const
{
	auto lside = lhs.eval(tq), rside = rhs.eval(tq);
	auto new_lines = new std::set<line_no>;
	std::set_intersection(lside.begin(), lside.end(), rside.begin(), rside.end(),
			      std::inserter(*new_lines, new_lines->end()));
	return {rep(), lside.get_file(), new_lines};
}

inline Query operator&(const Query& l, const Query& r)
{
	return new AndQuery(l, r);
}

#endif // _AndQuery_h_
