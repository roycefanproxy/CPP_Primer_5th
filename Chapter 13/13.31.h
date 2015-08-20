#ifndef _13_31_h_
#define _13_31_h_
#include <iostream>
#include <string>

class HasPtr;
void swap(HasPtr&, HasPtr&);
bool operator<(const HasPtr&, const HasPtr&);

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr&, const HasPtr&);
public:
	HasPtr(const std::string& s = std::string()) : data(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : data(new std::string(*hp.data)), i(hp.i) {}
	HasPtr& operator=(HasPtr hp)
	{
		using std::swap;
		swap(*this, hp);
		
		return *this;
	}
	void show()
	{
		std::cout << *data << std::endl;
	}
	~HasPtr() { delete data; }
private:
	void swap(HasPtr& hp)
	{
		using std::swap;
		swap(data, hp.data);
		swap(i, hp.i);
		std::cout << "swap is being executed." << std::endl;
	}

	std::string *data;
	int i;
};

void swap(HasPtr& a, HasPtr& b)
{
	a.swap(b);
}

bool operator<(const HasPtr& a, const HasPtr& b)
{
	return *a.data < *b.data;
}

#endif //_13_31_h_
