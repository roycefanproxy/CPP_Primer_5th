#ifndef _OrQuery_h_
#define _OrQuery_h_
#include <string>
#include <memory>
#include "Query.h"
#include "Query_Base.h"
#include "TextQuery.h"
#include "BinaryQuery.h"

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query& l, const Query& r);
private:
	OrQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "|") {}
	QueryResult eval(const TextQuery&) const override;
};

QueryResult OrQuery::eval(const TextQuery& tq) const
{
	auto right = rhs.eval(tq), left = lhs.eval(tq);
	auto ret_val = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_val->insert(right.begin(), right.end());
	return {rep(), ret_val, left.get_file()};
}

inline Query operator|(const Query& l, const Query& r)
{
	return std::shared_ptr<Query_Base>(new OrQuery(l, r));
}

#endif // _OrQuery_h_
