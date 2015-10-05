#ifndef _QUERY_BASE_H_
#define _QUERY_BASE_H_
#include <string>
#include "TextQuery.h"

class Query_Base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_Base() = default;
private:
	virtual std::string rep() const = 0;
	virtual QueryResult eval(const TextQuery&) const = 0;
};

#endif // _QUERY_BASE_H_
