#ifndef _13_39_h_
#define _13_39_h_
#include <string>
#include <memory>
#include <utility>
class Strvec
{
public:
	Strvec() : first(nullptr), first_free(nullptr), cap(nullptr) {}
	Strvec(const Strvec&);
	Strvec& operator=(const Strvec&);
	~Strvec() { free(); }

	void push_back(const std::string& s);
	size_t size() const { return first_free - first; };
	size_t capacity() const { return cap - first; };
	void resize(size_t, const std::string&);
	void reserve(size_t);
	std::string* begin() const { return first; }
	std::string* end() const { return first_free; }
private:
	void free();
	void reallocate();
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void chk_n_alloc();
	// private attributes
	std::string* first, *first_free, *cap;
	std::allocator<std::string> alloc;
};

void Strvec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

Strvec::Strvec(const Strvec& sv)
{
	auto newd = alloc_n_copy(sv.begin(), sv.end());
	first = newd.first;
	first_free = cap = newd.second;
}

Strvec& Strvec::operator=(const Strvec& sv)
{
	auto newd = alloc_n_copy(sv.begin(), sv.end());
	free();
	first = newd.first;
	first_free = cap = newd.second;

	return *this;
}

std::pair<std::string*, std::string*>
Strvec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto newd = alloc.allocate(e - b);

	return std::make_pair(newd, std::uninitialized_copy(b, e, newd));
}

void Strvec::chk_n_alloc()
{
	if(first_free == cap)
		reallocate();
}

void  Strvec::reallocate()
{
	size_t newcapacity = size() ? size() * 3 : 1;
	auto newd = alloc.allocate(newcapacity);
	auto newp = newd, oldp = first;
	while(oldp != first_free)
		alloc.construct(newp++, std::move(*(oldp++)));
	free();
	first = newd;
	first_free = newp;
	cap = newd + newcapacity;
}

void Strvec::free()
{
	while(first_free != first)
		alloc.destroy(--first_free);
	alloc.deallocate(first, cap - first);
}

void Strvec::resize(size_t n, const std::string& s = std::string())
{
	if(n < size())
	{
		while(size() != n)
			alloc.destroy(--first_free);
	}
	else if(n > size())
	{
		if(n <= capacity())
			while(size() != n)
			{
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

#endif 		//_13_39_h_
