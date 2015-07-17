#include <iostream>
#include <cctype>

int main()
{
    int c(0);
    std::string x;
    std::getline(std::cin, x);
    while(c < x.size())
    {
        x[c] = toupper(x[c]);
        c++;
    }
    std::cout << "While loop : \n" << x << std::endl;
    for(c = 0; c < x.size(); c++)
        x[c] = tolower(x[c]);
    std::cout << "Traditional for loop : \n" << x << std::endl;

    return 0;
}
