#include <iostream>
#include <string>
#include <functional>
#include <unordered_set>
#include "Sales_Item.h"
using namespace std;

size_t haser(const Sales_item& SD)
{
    return hash<string>()(SD.isbn());
}
bool compareISBN(const Sales_item& l, const Sales_item& r)
{
    return l.isbn() == r.isbn();
}

int main()
{
    unordered_set<Sales_item, decltype(&haser), decltype(&compareISBN)> test(15, haser, compareISBN);
}
