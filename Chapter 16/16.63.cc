#include <iostream>
#include <vector>
#include <string>

template <typename T1, typename T2>
unsigned find(const T1& ct, const T2& val)
{
    unsigned ret = 0;
    for(const auto& x : ct)
        if(x == val)
            ++ret;
    return ret;
}

int main()
{
    std::vector<std::string> vi;
    for(double i = 1; i <= 20.0; ++i)
        for(double y = 0; y != i; y+=0.2)
            vi.push_back(std::to_string(i));

    double val;
    std::cin >> val;

    std::cout << find(vi, std::to_string(val)) << std::endl;

    return 0;
}
