#include "15.26.h"
#include <vector>
#include <memory>
using namespace std;

int main()
{
	vector<shared_ptr<Quote>> basket;

	basket.push_back(make_shared<Quote>("Book Normal", 15.99));
	basket.push_back(make_shared<Bulk_Quote>("Book Discount", 20, 5, 0.1));

	for(auto& item : basket)
		cout << item->net_price(3) << endl;

	cout << basket[1]->net_price(5) << endl;

	return 0;
}
