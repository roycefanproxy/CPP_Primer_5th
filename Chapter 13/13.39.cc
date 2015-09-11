#include <iostream>
#include "13.39.h"
using namespace std;

int main()
{
	Strvec test;
	string buff;

	while(cin >> buff && buff != "q")
		test.push_back(buff);

	for(auto i = test.begin(); i != test.end(); ++i)
		cout << *i << endl;

	return 0;
}
