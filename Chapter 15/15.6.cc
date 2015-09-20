#include "15.5.h"
using namespace std;

int main()
{
	Bulk_Quote test("The Book", 26.99, 3, 0.20);
	Quote test2("Quote Book", 45.60);

	print_total(cout, test, 1);
	print_total(cout, test, 2);
	print_total(cout, test, 3);
	print_total(cout, test, 4);
	print_total(cout, test2, 3);
	print_total(cout, test2, 10);
	
	return 0;
}
