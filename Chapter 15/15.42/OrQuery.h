#ifndef _ORQUERY_H_
#define _ORQUERY_H_
#include "BinaryQuery.h"
#include "Query.h"
#include "TextQuery.h"


class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
private:
	OrQuery(const Query& ls, const Query& rs) : BinaryQuery(ls, rs, "|") {}
	QueryResult eval(const TextQuery&) const override;
};

inline
Query operator|(const Query& ls, const Query& rs)
{
	return Query(std::shared_ptr<Query_Base>(new OrQuery(ls, rs)));
}

#endif // _ORQUERY_H_
