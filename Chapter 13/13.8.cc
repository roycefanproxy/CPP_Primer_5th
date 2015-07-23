#include <iostream>
#include <string>

class HasPtr;
void print(std::ostream&, const HasPtr&);

class HasPtr
{
    friend void print(std::ostream&, const HasPtr&);

public:
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr& operator=(const HasPtr& hp)
    {
        auto temp(hp);
        delete this->ps;
        this->ps = temp.ps;
        this->i = temp.i;

        return *this;
    }

private:
    std::string* ps;
    int i;
};

int main()
{
    HasPtr *test = new HasPtr("test1");
    HasPtr test2(*test);
    HasPtr test3 = HasPtr("test2");

    print(std::cout, *test);
    print(std::cout, test2);
    delete test;
    //print(std::cout, *test);
    print(std::cout, test3);

    return 0;
}

void print(std::ostream& os, const HasPtr& hp)
{
    os << *hp.ps << ' ' << hp.i << std::endl;
}
