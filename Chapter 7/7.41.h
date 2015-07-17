#ifndef _7_41_h_
#define _7_41_h_
#include <iostream>

class Sales_Data
{
public:
    typedef unsigned pos;
    Sales_Data(std::string s, pos height, pos width) : contents(s), h(height), w(width)
    {
        std::cout << "This is parameter list constructor." << std::endl;
    }
    Sales_Data() : Sales_Data("", 15, 20) { std::cout << "This is default constructor." << std::endl; }
    Sales_Data(std::istream& is) : Sales_Data()
    {
        read(is);
        std::cout << "This is input stream parameter constructor." << std::endl;
    }
    Sales_Data& read(std::istream& is)
    {
        is >> contents >> h >> w;

        return *this;
    }
private:
    pos h, w, cursor = 0;
    std::string contents;
};
#endif // _7_41_h_
