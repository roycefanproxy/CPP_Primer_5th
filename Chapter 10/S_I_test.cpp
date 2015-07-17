#include "Sales_Item.h"
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<Sales_item> ois(cout, "\n");
    istream_iterator<Sales_item> iis(cin), eof;
    Sales_item sum = *iis++;

    while(iis != eof)
    {
        if(sum.isbn() == iis->isbn())
            sum += *iis++;
        else
        {
            ois = sum;
            sum = *iis++;
        }
    }
    ois = sum;

}
