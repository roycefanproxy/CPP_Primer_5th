#ifndef _16_52_H_
#define _16_52_H_
#include <iostream>

template <typename T, typename... Args>
void g(const T&, const Args& ... args)
{
    std::cout << sizeof...(Args) << '\n';
    std::cout << sizeof...(args) << std::endl;
}

int main()
{
    g(5, "test", 2.5f, 0.00006, 'c', 25L);

    return 0;
}

#endif // _16_52_H_
