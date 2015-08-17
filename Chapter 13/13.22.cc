#include <string>
#include <iostream>
using namespace std;

static int c = 1;
class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) : str_p(new std::string(s)), ival(c++) {}
	HasPtr(const HasPtr& hp) : str_p(new std::string(*hp.str_p)), ival(hp.ival) {}
	HasPtr& operator=(const HasPtr& hp)
	{
		std::string *temp = new std::string(*hp.str_p);
		delete str_p;
		str_p = temp;
		ival = hp.ival;
		
		return *this;
	}
	~HasPtr()
	{
		delete str_p;
	}
	std::string* str_p;
	int ival;
};

int main()
{
	HasPtr a("a"), b(a), c("b");
	
	cout << "a " << *a.str_p << ' ' << a.ival << endl;
	cout << "b " << *b.str_p << ' ' << b.ival << endl;
	cout << "c " << *c.str_p << ' ' << c.ival << endl;
	b = c;
	cout << "b " << *b.str_p << ' ' << b.ival;
	
	return 0;
}