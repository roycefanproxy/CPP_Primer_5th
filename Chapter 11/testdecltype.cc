#include <iostream>

const int f(const int);

int main()
{
    decltype(&f) x(f);

    std::cout << x(5) << std::endl;
}

const int f(const int i)
{
    return i;
}
