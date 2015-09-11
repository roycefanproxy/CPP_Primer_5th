#include <iostream>
#include "13.43.h"
using namespace std;

int main()
{
	Strvec test;
	const string buff("test ");
	int counter = 0;
	
	while(counter++ != 30)
	{
		test.push_back(buff + std::to_string(counter));
	}

	for(auto i = test.begin(); i != test.end(); ++i)
		cout << *i << endl;

	cout << '\n';
	cout << "Vector size : " << test.size() << endl;
	cout << "Vector capacity : " << test.capacity() << endl;
	cout << "Reserve 100 space." << endl;
	test.reserve(100);
	cout << "Show reserved capacity : " << test.capacity() << endl;

	return 0;
}


