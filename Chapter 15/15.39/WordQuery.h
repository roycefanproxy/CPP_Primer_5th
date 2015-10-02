#ifndef _WordQuery_h_
#define _WordQuery_h_
#include <string>
#include "Query.h"
#include "Query_Base.h"
#include "TextQuery.h"

class WordQuery : public Query_Base
{
	friend class Query;
private:
	WordQuery(const std::string& s) : word(s) {}
	std::string rep() const override { return word; }
	QueryResult eval(const TextQuery& tq) const override { return tq.query(word); }
	//	attribute
	std::string word;
};

#endif // _WordQuery_h_
