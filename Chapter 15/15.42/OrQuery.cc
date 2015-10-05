#include "OrQuery.h"
#include "TextQuery.h"
#include "Query.h"

QueryResult OrQuery::eval(const TextQuery& tq) const
{
	auto lresult = lhs.eval(tq), rresult = rhs.eval(tq);
	auto ret_val = std::make_shared<std::set<line_no>>(lresult.begin(), lresult.end());
	ret_val->insert(rresult.begin(), rresult.end());
	return QueryResult(rep(), lresult.get_file(), ret_val);
}

