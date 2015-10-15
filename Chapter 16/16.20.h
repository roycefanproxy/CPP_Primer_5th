#ifndef _16_20_H_
#define _16_20_H_
#include <iostream>

template<typename T>
void print(const T& con)
{
	for(auto& item : con)
		std::cout << item << std::endl;
}

#endif // _16_20_H_
