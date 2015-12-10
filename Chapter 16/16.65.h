#ifndef _16_65_H_
#define _16_65_H_
#include <string>
#include <sstream>

template <typename T>
inline std::string debug_rep(const T& item)
{
    std::ostringstream output;
    output << '"' << item << '"';
    return output.str();
}

template <>
inline std::string debug_rep(char* const &item)
{
    std::cout << "char* ver" << std::endl;
    return std::string(item);
}

template <>
inline std::string debug_rep(const char * const &item)
{
    return std::string(item);
}

#endif // _16_65_H_
