#ifndef _Query_h_
#define _Query_h_
#include <string>
#include "TextQuery.h"
#include "Query_Base.h"
#include "WordQuery.h"

class Query
{
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator~(const Query&);
public:
	Query(const std::string& s) : query(new WordQuery(s)), counter(new int(1)) {}
	Query(const Query& q) : query(q.query), counter(q.counter) { ++*counter; }
	Query& operator=(const Query& q)
	{
		if(this != &q)
		{
			if(--*counter == 0)
			{
				delete query;
				delete counter;
			}
			counter = q.counter;
			std::cout << ++*counter << std::endl;;
			query = q.query;
		}
		return *this;
	}
	~Query()
	{
		if(--*counter == 0)
		{
			delete query;
			delete counter;
		}
	}
	std::string rep() const { return query->rep(); }
	QueryResult eval(const TextQuery& tq) const { return query->eval(tq); }
private:
	Query(Query_Base* qb) : query(qb), counter(new int(1)) {}

	Query_Base* query;
	int* counter;
};

#endif // _Query_h_
