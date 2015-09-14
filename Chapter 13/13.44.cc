#include "13.44.h"
using namespace std;

int main()
{
	String test1;

	for(int i = 0; i != 10; ++i)
		test1.push_back('a' + i);
	
	print(test1);
	
	return 0;
}

