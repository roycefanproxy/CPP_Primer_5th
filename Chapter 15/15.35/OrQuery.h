#ifndef _OrQuery_h_
#define _OrQuery_h_
#include <string>
#include <memory>
#include "Query.h"
#include "Query_Base.h"
#include "BinaryQuery.h"

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
private:
	OrQuery(const Query& l, const Query& r)
		: BinaryQuery(l, r, "|") {}
};

inline Query operator|(const Query& l, const Query& r)
{
	return std::shared_ptr<Query_Base>(new OrQuery(l, r));
}

#endif // _OrQuery_h_
