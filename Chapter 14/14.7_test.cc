#include "14.7.h"
#include <vector>
using namespace std;

int main()
{
	vector<String> test;
	char buff[10] = "test ";
	for(int i = 0; i != 20; ++i)
	{
		buff[5] = '0' + i;
		test.push_back(buff);
	}

	for(auto i = test.begin(); i != test.end(); ++i)
		cout << *i << endl;

	return 0;
}
