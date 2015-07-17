#include <iostream>
#include <cctype>

int main()
{
    std::string s;
    while(std::getline(std::cin, s))
    {
        for(char& c : s)
        {
            if(!ispunct(c))
                std::cout << c;
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
}
