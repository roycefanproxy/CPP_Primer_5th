#ifndef _13_30_h_
#define _13_30_h_
#include <string>
#include <iostream>

class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) : data(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : data(new std::string(*hp.data)), i(hp.i) {}
	HasPtr& operator=(const HasPtr& hp)
	{
		auto temp = new std::string(*hp.data);
		int tempi = hp.i;
		delete data;
		data = temp;
		i = tempi;
		return *this;
	}

	void swap(HasPtr& lv, HasPtr& rv)
	{
		using std::swap;
		swap(lv.data, rv.data);
		swap(lv.i, rv.i);
		std::cout << "Swap is being called." << std::endl;
	}
	
	~HasPtr() { delete data; }
private:
	std::string* data;
	int i;
};
#endif //_13_30_h_
