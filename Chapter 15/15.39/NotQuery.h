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
	std::string rep() const override
	{
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery&) const override;

	Query query;
};

QueryResult NotQuery::eval(const TextQuery& tq) const
{
	auto result = query.eval(tq);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto result_no = result.begin();
	auto size = result.get_file()->size();
	for(line_no counter = 0; counter != size; ++counter)
	{
		if(counter != *result_no || result_no == result.end())
			ret_lines->insert(counter);
		else if(result_no != result.end())
			++result_no;
	}
	return {rep(), ret_lines, result.get_file()};
}

inline Query operator~(const Query& q)
{
	return std::shared_ptr<Query_Base>(new NotQuery(q));
}

#endif // _NotQuery_h_
