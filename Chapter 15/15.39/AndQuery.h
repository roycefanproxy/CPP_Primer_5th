#ifndef _AndQuery_h_
#define _AndQuery_h_
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include "Query.h"
#include "BinaryQuery.h"
#include "Query_Base.h"
#include "TextQuery.h"

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "&") {}
	QueryResult eval(const TextQuery&) const override;
};

QueryResult AndQuery::eval(const TextQuery& tq) const
{
	auto left = lhs.eval(tq), right = rhs.eval(tq);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
	return {rep(), ret_lines, left.get_file()};
}

inline Query operator&(const Query& l, const Query& r)
{
	return std::shared_ptr<Query_Base>(new AndQuery(l, r));
}

#endif // _AndQuery_h_
