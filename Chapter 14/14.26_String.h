#ifndef _14_26_h_
#define _14_26_h_
#include <memory>
#include <utility>
#include <iostream>
#include <cstring>

class String;
std::ostream& operator<<(std::ostream&, const String&);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);
bool operator<(const String&, const String&);
bool operator>(const String&, const String&);

class String
{
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend bool operator==(const String& ls, const String& rs);
	friend bool operator<=(const String&, const String&);
	friend bool operator>=(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator<(const String&, const String&);

public:
	String() : first(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String& operator=(String&&) noexcept;
	~String();
	size_t size() const;
	char* begin() const;
	char* end() const;
	char& operator[](size_t n);
	const char& operator[](size_t n) const;
private:
	void range_ini(const char*);
	void free();
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	std::allocator<char> alloc;
	char *first, *cap;
};

String::String(const char* p)
{
	range_ini(p);
}

String::String(const String& s)
{
	range_ini(s.begin());
}

char& String::operator[](size_t n)
{
	return first[n];
}

const char& String::operator[](size_t n) const
{
	return first[n];
}

String& String::operator=(const String& s)
{
	auto newd = alloc_n_copy(s.begin(), s.end());
	free();
	first = newd.first;
	cap = newd.second;
	return *this;
}

String& String::operator=(String&& s) noexcept
{
	if(this != &s)
	{
		free();
		first = s.first;
		cap = s.cap;
		s.first = s.cap = nullptr;
	}
	return *this;
}

String::~String()
{
	free();
}

size_t String::size() const
{
	return cap - first;
}

char* String::begin() const
{
	return first;
}

char* String::end() const
{
	return cap;
}

void String::range_ini(const char* b)
{
	auto e = b;
	while(*e++ != '\0')
		continue;
	auto newd = alloc_n_copy(b, e);
	first = newd.first;
	cap = newd.second;
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto newd = alloc.allocate(e - b);
	return { newd, std::uninitialized_copy(b, e, newd)};
}

void String::free()
{
	for(auto itr = first; itr != cap; ++itr)
		alloc.destroy(itr);
	alloc.deallocate(first, cap - first);
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.first;
	return os;
}

bool operator==(const String& ls, const String& rs)
{
	return strcmp(ls.first, rs.first) ? false : true;
}

bool operator!=(const String& ls, const String& rs)
{
	return !(ls == rs);
}

bool operator<=(const String& ls, const String& rs)
{
	return !(rs < ls);
}

bool operator>=(const String& ls, const String& rs)
{
	return !(ls < rs);
}

bool operator<(const String& ls, const String& rs)
{
	return strcmp(ls.first, rs.first) < 0 ? true : false;
}

bool operator>(const String& ls, const String& rs)
{
	return rs < ls;
}

#endif // _14_26_h_
