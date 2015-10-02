#ifndef _BinaryQuery_h_
#define _BinaryQuery_h_
#include <string>
#include "Query.h"
#include "Query_Base.h"

class BinaryQuery: public Query_Base
{
protected:
	BinaryQuery(const Query& ls, const Query& rs, const std::string& s)
		: lhs(ls), rhs(rs), op_sym(s) {}
	std::string rep() const override;

	Query lhs, rhs;
private:
	std::string op_sym;
};

std::string BinaryQuery::rep() const
{
	return "(" + lhs.rep() + " " + op_sym + " " + rhs.rep() + ")";
}

#endif // _BinaryQuery_h_
