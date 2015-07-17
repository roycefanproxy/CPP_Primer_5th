#include <iostream>
#include <string>
using std::string;

/*******************************************
 *                                         *
 *    The answer is false                  *
 *                                         *
 *******************************************/
constexpr bool is_shorter(const string&, const string&);

int main()
{
    constexpr string t = "this is awesome.", t2 = "this is awesome. Don't you think so?";
    std::cout << (is_shorter(t, t2)? "True" : "False") << std::endl;

    return 0;
}

constexpr bool is_shorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}
