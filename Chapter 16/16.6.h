#ifndef _16_6_h_
#define _16_6_h_
#include <cstddef>

template<typename T, std::size_t N>
T* begin(T (&arr)[N])
{
	return arr;
}

template<typename T, std::size_t N>
T* end(T (&arr)[N])
{
	return arr + N;
}

#endif // _16_6_h_
