#include <set>
#include <iostream>
#include <string>
#include "Sales_Item.h"
using namespace std;

bool compare_Isbn(const Sales_item&, const Sales_item&);

int main()
{
    multiset<Sales_item, bool (*)(const Sales_item&, const Sales_item&)> msfp(compare_Isbn);
    Sales_item item;

    while(cin >> item)
        msfp.insert(item);

    for(auto& x : msfp)
        cout << *msfp.find(x) << endl;
}

bool compare_Isbn(const Sales_item& a, const Sales_item& b)
{
    return a.isbn() < b.isbn();
}
