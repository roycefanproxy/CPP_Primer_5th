#include <string>

class HasPtr
{
    std::string *ps;
    int i;

public:
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr& operator=(const HasPtr& hp)
    {
        auto temp(hp);
        delete ps;
        ps = new std::string(*temp.ps);
        i = temp.i;

        return *this;
    }

    ~HasPtr()
    {
        delete ps;
    }
};

int main()
{
    HasPtr *test1 = new HasPtr("test");
    HasPtr test2(*test1);
    delete test1;
    HasPtr test3 = test2;

    return 0;
}
