#include "15.26.h"
using namespace std;

int main()
{
	Bulk_Quote test("bq", 15.99, 3, 0.2), test2(test);

	Bulk_Quote test3;

	test3 = test2;

	for(int i = 0; i != 5; ++i)
	{
		Quote("temp q", 10.00);
		Bulk_Quote("temp bq", 20.50, 4, 0.1);
	}

	Quote testq("testq", 13.00);
	cout << testq.net_price(5) << endl;
	Quote& t = test3;
	cout << t.net_price(5) << endl;

	return 0;
}
