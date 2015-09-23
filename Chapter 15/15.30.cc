#include "15.30.h"
using namespace std;

int main()
{
	Basket items;
	items.add_item(Quote("quote book", 15));
	items.add_item(Bulk_Quote("bulk_quote book", 25, 3, 0.2));
	items.add_item(Bulk_Quote("bulk_quote book", 25, 3, 0.2));
	items.add_item(Bulk_Quote("bulk_quote book", 25, 3, 0.2));
	items.add_item(Quote("quote book", 15));
	items.add_item(Bulk_Quote("bulk_quote book", 25, 3, 0.2));
	items.add_item(Quote("quote book", 15));

	cout << "Total price : " << items.total_receipt(cout) << endl;

	return 0;
}

