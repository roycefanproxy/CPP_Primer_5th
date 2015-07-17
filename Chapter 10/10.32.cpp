#include <iostream>
#include <vector>
#include "Sales_Item.h"
#include <algorithm>

bool compare_isbn(const Sales_item&, const Sales_item&);

int main()
{
    std::vector<Sales_item> vsi;
    Sales_item input;
    std::vector<Sales_item>::iterator sum;

    while(std::cin >> input)
        vsi.push_back(input);
    std::sort(vsi.begin(), vsi.end(), compare_isbn);
    for(auto itr = vsi.cbegin(), end = itr; itr != vsi.cend(); itr = end)
    {
        end = std::find_if(itr, vsi.cend(), [=] (const Sales_item& item) { return itr->isbn() != item.isbn(); });
        std::cout << std::accumulate(itr, end, Sales_item(itr->isbn())) << std::endl;
    }

}

bool compare_isbn(const Sales_item& a, const Sales_item& b)
{
    return a.isbn() < b.isbn();
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "Sales_Item.h"

int main()
{
    std::istream_iterator<Sales_item> in_iter(std::cin), in_eof;
    std::vector<Sales_item> vec;

    while (in_iter != in_eof)
        vec.push_back(*in_iter++);
    std::sort(vec.begin(), vec.end(), compareIsbn);
    for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
        end = find_if(beg, vec.cend(), [beg](const Sales_item &item){return item.isbn() != beg->isbn();});
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << std::endl;
    }
}
*/
