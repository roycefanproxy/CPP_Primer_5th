#include "AndQuery.h"
#include <algorithm>
#include <iterator>

QueryResult AndQuery::eval(const TextQuery& tq) const
{
	auto lresult = lhs.eval(tq), rresult = rhs.eval(tq);
	auto new_ret = std::make_shared<std::set<line_no>>();
	std::set_intersection(lresult.begin(), lresult.end(), rresult.begin(), rresult.end(),
			      std::inserter(*new_ret, new_ret->end()));
	return QueryResult(rep(), lresult.get_file(), new_ret);
}
