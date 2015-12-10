#include <iostream>
#include <string>
#include <cstring>
#include <vector>

template <typename T1>
unsigned find(const std::vector<T1>& con)
{
    T1 val;
    std::cin >> val;
    unsigned ret = 0;
    for(const auto& x : con)
        if(val == x)
            ++ret;

    return ret;
}

template <>
unsigned find(const std::vector<const char*>& con)
{
    char val[20];

    std::cin >> val;

    unsigned ret = 0;
    for(const auto& x : con)
        if(strcmp(x, val) == 0)
            ++ret;
    return ret;
}

int main()
{
    std::vector<const char*> vcc;

    vcc.push_back("one");
    vcc.push_back("two");
    vcc.push_back("three");
    vcc.push_back("four");
    vcc.push_back("five");

    std::cout << find(vcc) << std::endl;

    return 0;
}
