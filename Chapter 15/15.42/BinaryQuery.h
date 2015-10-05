#ifndef _BINARYQUERY_H_
#define _BINARYQUERY_H_
#include <string>
#include "Query_Base.h"
#include "Query.h"

class BinaryQuery : public Query_Base
{
protected:
	BinaryQuery(const Query& ls, const Query& rs, const std::string& s)
		: lhs(ls), rhs(rs), op_sym(s) {}
	std::string rep() const override
	{
		return "(" + lhs.rep() + " " + op_sym + " " + rhs.rep() + ")";
	}

	Query lhs, rhs;
private:
	std::string op_sym;
};

#endif // _BINARYQUERY_H_
