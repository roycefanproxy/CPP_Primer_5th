#ifndef _NotQuery_h_
#define _NotQuery_h_
#include <string>
#include "Query.h"
#include "Query_Base.h"
#include "TextQuery.h"

class NotQuery : public Query_Base
{
	friend Query operator~(const Query&);
private:
	NotQuery(const Query& q) : query(q) {}
	std::string rep() const override { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery& tq) const override;

	Query query;
};

inline Query operator~(const Query& q)
{
	return new NotQuery(q);
}

QueryResult NotQuery::eval(const TextQuery& tq) const
{
	auto result = query.eval(tq);
	auto new_line_set = new std::set<line_no>;
	auto itr = result.begin();
	auto size = result.get_file()->size();
	for(line_no counter = 0; counter != size; ++counter)
	{
		if(counter != *itr || itr == result.end()) new_line_set->insert(counter);
		else if(itr != result.end()) ++itr;
	}
	return {rep(), result.get_file(), new_line_set};
}

#endif // _NotQuery_h_
