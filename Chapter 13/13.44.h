#ifndef _13_44_h_
#define _13_44_h_
#include <utility>
#include <memory>
#include <iostream>

class String;

void print(const String&);

class String
{
	friend void print(const String&);
public:
	String(const char*);
	String(const char*, const char*);
	String(const String&);
	String& operator=(const String&);	
	String& operator=(String&&) noexcept;
	~String();
	void push_back(const char&);
	void push_back(char&&);
	size_t size() const;
	char* begin() const;
	char* end() const;
private:
	std::allocator<char> alloc;
	char *first, *first_free, *cap;
	void free();
	void chk_n_alloc();
	void reallocate();
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
};

String::String(const char* b = nullptr) : first(nullptr), first_free(nullptr), cap(nullptr)
{
	if(b)
	{
		auto temp = b;
		while(*temp++ != '\0') continue;
		auto newd = alloc_n_copy(b, temp);
		first = newd.first;
		first_free = cap = newd.second;
	}
}

String::String(const char* b, const char* e)
{	
		auto newd = alloc_n_copy(b, e);
		first = newd.first;
		first_free = cap = newd.second;
}	
	
String::String(const String& s)
{
	auto newd = alloc_n_copy(s.begin(), s.end());
	first = newd.first;
	first_free = cap = newd.second;
}

String& String::operator=(const String& s)
{
	auto newd = alloc_n_copy(s.begin(), s.end());
	free();
	first = newd.first;
	first_free = cap = newd.second;
	return *this;
}

String& String::operator=(String&& s) noexcept
{
	if(this != &s)
	{
		free();
		first = s.first;
		first_free = s.first_free;
		cap = s.cap;
		s.first = s.first_free = s.cap = nullptr;
	}
	return *this;
}

String::~String() { free(); }

void String::push_back(const char& c)
{
	chk_n_alloc();
	*first_free++ = c;
}

void String::push_back(char&& c)
{
	chk_n_alloc();
	*first_free++ = std::move(c);
}

size_t String::size() const { return first_free - first; }

char* String::begin() const { return first; }

char* String::end() const { return first_free; }

void String::free()
{
	while(first_free != first)
		alloc.destroy(--first_free);
	alloc.deallocate(first, cap - first);
}

void String::chk_n_alloc()
{
	if(first_free == cap)
		reallocate();
}

void String::reallocate()
{
	auto news = size() ? size() * 3 : 2;
	auto newd = alloc.allocate(news);
	auto f_free = std::uninitialized_copy(std::make_move_iterator(first), std::make_move_iterator(cap), newd);
	free();
	first = newd;
	first_free = f_free;
	cap = first + news;
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto newd = alloc.allocate(e - b);
	return std::make_pair(newd, std::uninitialized_copy(b, e, newd));
}

void print(const String& s)
{
	std::cout << s.first << std::endl;
}

#endif // _13_44_h_
