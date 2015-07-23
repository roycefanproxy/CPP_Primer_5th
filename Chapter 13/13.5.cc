#include <iostream>
#include <string>

class HasPtr;
void print(std::ostream&, const HasPtr&);
class HasPtr
{
friend void print(std::ostream&, const HasPtr&);
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
private:
    std::string *ps;
    int i;
};

int main()
{
    HasPtr *test = new HasPtr("Test1");
    HasPtr test2(*test);
    delete test;

    print(std::cout, test2);

    return 0;
}

void print(std::ostream& os, const HasPtr& hp)
{
    os << *hp.ps << ' ' << hp.i << std::endl;
}
