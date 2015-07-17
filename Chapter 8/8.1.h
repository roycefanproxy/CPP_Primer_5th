#include <iostream>

std::istream& the_func(std::istream& is)
{
    std::string input;
    while(is >> input)
        std::cout << input << std::endl;

    is.clear();

    return is;
}
