#ifndef _14_40_h_
#define _13_40_h_
#include <string>
#include <utility>
#include <memory>
#include <initializer_list>

class Strvec
{
public:
	Strvec() : first(nullptr), first_free(nullptr), cap(nullptr) {}
	Strvec(std::initializer_list<std::string>);
	Strvec(const Strvec&);
	Strvec& operator=(const Strvec&);
	~Strvec() { free(); }

	void push_back(const std::string&);
	size_t size() const { return first_free - first; }
	size_t capacity() const { return cap - first; }
	void resize(size_t, const std::string&);
	void reserve(size_t);
	std::string* begin() const { return first; }
	std::string* end() const { return first_free; }
private:
	void chk_n_alloc();
	std::pair<std::string*, std::string*>
	alloc_n_copy(const std::string*, const std::string*);
	void reallocate();
	void free();
	void range_ini(const std::string*, const std::string*);
	//	private attributes
	std::string *first, *first_free, *cap;
	std::allocator<std::string> alloc;
};

Strvec::Strvec(std::initializer_list<std::string> arr)
{
	range_ini(arr.begin(), arr.end());
}

Strvec::Strvec(const Strvec& sv)
{
	range_ini(sv.begin(), sv.end());
}

Strvec& Strvec::operator=(const Strvec& sv)
{
	auto newd = alloc_n_copy(sv.begin(), sv.end());
	free();
	first = newd.first;
	first_free = cap = newd.second;

	return *this;
}

void Strvec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void Strvec::chk_n_alloc()
{
	if(first_free == cap)
		reallocate();
}

std::pair<std::string*, std::string*> Strvec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto newd = alloc.allocate(e - b);
	return std::make_pair(newd, std::uninitialized_copy(b, e, newd));
}

void Strvec::free()
{
	while(first_free != first)
		alloc.destroy(--first_free);
	alloc.deallocate(first, cap - first);
}

void Strvec::range_ini(const std::string* b, const std::string* e)
{
	first = alloc.allocate(e - b);
	first_free = cap = std::uninitialized_copy(b, e, first);
}

void Strvec::reallocate()
{
	auto newc = size() ? size() * 3 : 2;

	auto n_ptr = alloc.allocate(newc);
	auto o_ptr = first;
	auto itr = n_ptr;
	for(; o_ptr != cap; ++itr, ++o_ptr)
		alloc.construct(itr, std::move(*o_ptr));
	free();
	first = n_ptr;
	first_free = itr;
	cap = first + newc;
}

void Strvec::resize(size_t n, const std::string& s = std::string())
{
	if(n < size())
	{
		auto news = first + n;
		while(first_free != news)
			alloc.destroy(--first_free);
	}
	if(n > size())
	{
		if(n <= capacity())
		{
			auto news = first + n;
			while(first_free != news)
				alloc.construct(first_free++, s);
		}
		else
		{
			reallocate();
			resize(n, s);
		}
	}
}

void Strvec::reserve(size_t n)
{
	if(n > capacity())
	{
		auto newd = alloc.allocate(n);
		auto f_free = std::uninitialized_copy(first, first_free, newd);
		free();
		first = newd;
		first_free = f_free;
		cap = first + n;
	}
}

#endif // 13_49_h_
