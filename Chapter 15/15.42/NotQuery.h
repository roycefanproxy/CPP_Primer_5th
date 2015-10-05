#ifndef _NOTQUERY_H_
#define _NOTQUERY_H_
#include <string>
#include <memory>
#include "TextQuery.h"
#include "Query_Base.h"
#include "Query.h"

class NotQuery : public Query_Base
{
	friend Query operator~(const Query&);
private:
	NotQuery(const Query& q)
		: query(q) {}
	std::string rep() const override { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const override;

	Query query;
};

inline
Query operator~(const Query& q)
{
	return Query(std::shared_ptr<Query_Base>(new NotQuery(q)));
}

#endif // _NOTQUERY_H_
