#ifndef _WORDQUERY_H_
#define _WORDQUERY_H_
#include <string>
#include "TextQuery.h"

class WordQuery : public Query_Base
{
	friend class Query;
private:
	WordQuery(const std::string& s)
		: word(s) {}
	std::string rep() const override { return word; }
	QueryResult eval(const TextQuery& tq) const { return tq.query(word); }

	std::string word;
};

#endif // _WORDQUERY_H_
