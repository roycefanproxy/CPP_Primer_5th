#include <iostream>
#include <string>
#include "16.29.h"
using namespace std;

int main()
{
	Blob<string> test;

	for(int i = 0; i != 20; ++i)
		test.push_back(to_string(i + 1));
	for(auto& x : test)
		cout << x << endl;

	return 0;
}
