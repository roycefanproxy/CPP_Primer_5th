#include <iostream>

class test
{
public:
    int getter()
    {
        return initdata;
    }
    static constexpr int init(void);
private:

    static constexpr int initdata = 10;
};

constexpr int test::init(void) { return 20; }
int main()
{
    test test1;

    std::cout << test1.getter() << std::endl;
    std::cout << test::init() << std::endl;
}
