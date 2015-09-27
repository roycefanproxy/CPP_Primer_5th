#ifndef _16_4_h_
#define _16_4_h_

template<typename T, typename Iterator>
Iterator myFind(Iterator b, Iterator e, T& item)
{
	while(b != e)
	{
		if(*b == item) break;
		++b;
	}
	return b;
}

#endif // _16_4_h_
