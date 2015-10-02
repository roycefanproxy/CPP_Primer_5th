#ifndef _BinaryQuery_h_
#define _BinaryQuery_h_
#include <string>
#include "Query.h"
#include "Query_Base.h"

class BinaryQuery : public Query_Base
{
protected:
	BinaryQuery(const Query& l, const Query& r, const std::string& s)
		: lhs(l), rhs(r), op_symbol(s) {}
	std::string rep() const override { return "(" + lhs.rep() + " " + op_symbol + " " + rhs.rep() + ")"; }
	// attributes
	Query lhs, rhs;
	std::string op_symbol;
};

#endif // _BinaryQuery_h_
