#include <set>
#include <iostream>
#include "Sales_Item.h"

int main()
{
    std::set<Sales_item> bookstore;
    std::set<Sales_item>::iterator itr = bookstore.begin();
    auto x = [](const auto v) { return v; };

    std::cout << x("Hello World!") << std::endl;
}
