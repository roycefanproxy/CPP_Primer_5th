#ifndef _WordQuery_h_
#define _WordQuery_h_
#include <string>
#include "Query_Base.h"
#include "TextQuery.h"

class WordQuery : public Query_Base
{
	friend class Query;
private:
	WordQuery(const std::string&);
	QueryResult eval(const TextQuery&) const;
	std::string rep() const;
	std::string word;
};

WordQuery::WordQuery(const std::string& s) : word(s) {}

QueryResult WordQuery::eval(const TextQuery& tq) const override
{
	return tq.query(word);
}

std::string WordQuery::rep() const override
{
	return word;
}

#endif // _WordQuery_h_
