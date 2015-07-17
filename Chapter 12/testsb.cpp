#include <iostream>
#include "StrBlob.h"

int main()
{
    StrBlob test({"one", "two", "three", "four", "five"});

    try
    {
        test.front();
    }
    catch(std::out_of_range x)
    {
        std::cout << x.what() << std::endl;
    }
    test.push_back("test");

    std::cout << test.front() << std::endl;
}
