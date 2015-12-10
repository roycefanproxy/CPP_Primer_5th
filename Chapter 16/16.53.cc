#include <iostream>
using std::ostream;

template<typename T>
ostream& print(ostream& os, const T& t)
{
    return os << t;
}

template<typename T, typename ... Args>
ostream& print(ostream& os, const T& t, Args ... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main()
{
    print(std::cout, 15, 0.999, "string", 5.212f, 4L) << std::endl;

    return 0;
}
