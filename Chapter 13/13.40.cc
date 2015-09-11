#include <iostream>
#include "13.40.h"

int main()
{
	Strvec test;
	std::string buff;

	while(std::cin >> buff && buff != "q")
		test.push_back(buff);
	for(auto itr = test.begin(); itr != test.end(); ++itr)
		std::cout << *itr << std::endl;

	return 0;
}
