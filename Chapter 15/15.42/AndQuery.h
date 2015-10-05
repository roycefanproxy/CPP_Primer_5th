#ifndef _ANDQUERY_H_
#define _ANDQUERY_H_
#include "BinaryQuery.h"
#include <memory>

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query& ls, const Query& rs) : BinaryQuery(ls, rs, "&") {}
	QueryResult eval(const TextQuery&) const override;
};

inline
Query operator&(const Query& ls, const Query& rs)
{
	return Query(std::shared_ptr<Query_Base>(new AndQuery(ls, rs)));
}

#endif // _ANDQUERY_H_
