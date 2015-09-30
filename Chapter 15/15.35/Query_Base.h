#ifndef _Query_Base_h_
#define _Query_Base_h_
#include <memory>
#include <string>

//	This is only an abstract class.
class  Query_Base
{
	friend class Query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_Base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

#endif // _Query_Base_h_
