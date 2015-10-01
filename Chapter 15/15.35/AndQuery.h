#ifndef _AndQuery_h_
#define _AndQuery_h_
#include <string>
#include <memory>
#include "Query.h"
#include "BinaryQuery.h"

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query& l, const Query& r)
		: BinaryQuery(l, r, "&") {}
};

inline Query operator&(const Query& l, const Query& r)
{
	return std::shared_ptr<Query_Base>(new AndQuery(l, r));
}

#endif // _AndQuery_h_
