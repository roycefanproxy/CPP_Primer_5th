#include <iostream>

std::string (&func())[10]
{
    static std::string temp[10];

    return temp;
}

int main()
{
    int i = 0, y;
    auto x = func();
    for(y = 0; y < 10; ++y)
        x[y] = '0' + i++;

    for(y = 0; y < 10; ++y)
        std::cout << x[y] << std::endl;


}
