#ifndef _16_5_h_
#define _16_5_h_
#include <iostream>

template<typename T, size_t N>
void print(std::ostream& os, T (&arr)[N])
{
	for(auto i = 0; i != N; ++i)
		os << arr[i] << std::endl;
}

#endif // _16_5_h_
