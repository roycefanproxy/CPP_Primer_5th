#ifndef _NotQuery_h_
#define _NotQuery_h_
#include <string>
#include <memory>
#include "Query.h"
#include "Query_Base.h"

class NotQuery : public Query_Base
{
	friend Query operator~(const Query&);
private:
	NotQuery(const Query& q) : query(q) {}
	std::string rep() const override { return "~(" << query.rep() << ")"; }

	Query query;
};

inline Query operator~(const Query& q)
{
	return std::shared_ptr<Query_Base>(new NotQuery(q));
}

#endif // _NotQuery_h_
