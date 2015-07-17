#include <iostream>

int main()
{
    auto x = [] (const int a, const int b) { return a + b; };
    int a, b;
    std::cin >> a >> b;
    std::cout << x(a, b) << std::endl;

    return 0;
}
