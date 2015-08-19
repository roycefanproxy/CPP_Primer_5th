#ifndef _13_27_h_
#define _13_27_h_
#include <string>

class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) :
		strp(new std::string(s)), use(new int(1)), i(0) {}
	HasPtr(const HasPtr& hp) : strp(hp.strp), i(hp.i), use(hp.use)
	{
		++(*use);
	}
	HasPtr& operator=(const HasPtr& hp)
	{
		++(*hp.use);
		if(--(*use) == 0)
		{
			delete strp;
			delete use;
		}
		strp = hp.strp;
		i = hp.i;
		use = hp.use;

		return *this;
	}
	~HasPtr()
	{
		if(--(*use) == 0)
		{
			delete strp;
			delete use;
		}
	}
		
private:
	std::string* strp;
	int i;
	int *use;
};

#endif //_13_27_h_
