#ifndef _16_19_H_
#define _16_19_H_
#include <iostream>

template<typename T>
void print(const T& con)
{
	auto itr = con.begin();
	for(typename T::size_type i = 0; i != con.size(); ++i)
		std::cout << *(itr + i) << std::endl;
}

#endif // _16_19_H_
