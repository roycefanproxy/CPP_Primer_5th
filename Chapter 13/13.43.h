#ifndef _13_43_h_
#define _13_43_h_
#include <string>
#include <utility>
#include <memory>
#include <algorithm>
#include <initializer_list>

class Strvec
{
public:
	Strvec() : first(nullptr), first_free(nullptr), cap(nullptr) {}
	Strvec(std::initializer_list<std::string>);
	Strvec(const Strvec&);
	Strvec& operator=(const Strvec&);
	~Strvec();
	void push_back(const std::string&);
	void resize(size_t, const std::string&);
	void reserve(size_t);
	size_t capacity() const;
	size_t size() const;
	std::string* begin() const;
	std::string* end() const;
private:
	void chk_n_alloc();
	void reallocate();
	void free();
	void list_ini(const std::string*, const std::string*);
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	std::string *first, *first_free, *cap;
	std::allocator<std::string> alloc;
};

Strvec::Strvec(std::initializer_list<std::string> ls)
{
	list_ini(ls.begin(), ls.end());
}

Strvec::Strvec(const Strvec& sv)
{
	list_ini(sv.begin(), sv.end());
}

Strvec& Strvec::operator=(const Strvec& sv)
{
	auto newd = alloc_n_copy(sv.begin(), sv.end());
	free();
	first = newd.first;
	first_free = cap = newd.second;
	return *this;
}

Strvec::~Strvec()
{
	free();
}

void Strvec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void Strvec::resize(size_t n, const std::string& s = std::string())
{
	if(n < size())
	{
		auto news = first + n;
		while(first_free != news)
			alloc.destroy(--first_free);
	}
	else if(n > size())
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
		auto f_free = newd, o_first = first;
		while(o_first != first_free)
			alloc.construct(f_free++, std::move(*(o_first++)));
		free();
		first = newd;
		first_free = f_free;
		cap = newd + n;
	}
}

size_t Strvec::size() const
{
	return first_free - first;
}

size_t Strvec::capacity() const
{
	return cap - first;
}

std::string* Strvec::begin() const
{
	return first;
}

std::string* Strvec::end() const
{
	return first_free;
}

void Strvec::chk_n_alloc()
{
	if(first_free == cap)
		reallocate();
}

void Strvec::free()
{
	std::for_each(first, first_free, [&](auto p) { this->alloc.destroy(&p); });
	alloc.deallocate(first, cap - first);
}

void Strvec::reallocate()
{
	auto newc = size() ? size() * 3 : 2;
	auto newd = alloc.allocate(newc);
	auto o_first = first, n_first = newd;
	while(o_first != first_free)
		alloc.construct(n_first++, std::move(*(o_first++)));
	free();
	first = newd;
	first_free = n_first;
	cap = newd + newc;
}

void Strvec::list_ini(const std::string* b, const std::string* e)
{
	auto newd = alloc_n_copy(b, e);
	first = newd.first;
	first_free = cap = newd.second;
}

std::pair<std::string*, std::string*> Strvec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto newd = alloc.allocate(e - b);
	return {newd, std::uninitialized_copy(b, e, newd)};
}

#endif // _13_43_h_
