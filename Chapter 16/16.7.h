#ifndef _16_7_h_
#define _16_7_h_
#include <cstddef>

template<typename T, std::size_t N>
decltype(N) get_size(const T (&)[N])
{
	return N;
}

#endif // _16_7_h_
