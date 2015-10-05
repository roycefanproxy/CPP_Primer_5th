#include "TextQuery.h"
#include "NotQuery.h"
#include "Query.h"

QueryResult NotQuery::eval(const TextQuery& tq) const
{
	auto result = query.eval(tq);
	auto new_ret = std::make_shared<std::set<line_no>>();
	auto itr = result.begin();
	for(line_no new_no = 0; new_no != result.get_file()->size(); ++new_no)
	{
		if(new_no != *itr || itr == result.end())
			new_ret->insert(new_no);
		if(itr != result.end())
			++itr;
	}

	return {rep(), result.get_file(), new_ret};
}
