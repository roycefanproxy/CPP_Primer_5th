#ifndef _16_16_H_
#define _16_16_H_
#include <memory>
#include <utility>

template<typename T>
class Vec
{
public:
	typedef size_t size_type;
	Vec() : first(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(std::initializer_list<T> il)
	{
		auto new_d = alloc_n_copy(il.begin(), il.end());
		first = new_d.first;
		first_free = cap = new_d.second;
	}
	Vec(const Vec&);
	Vec& operator=(Vec);
	~Vec() { free(); }

	size_type size() const { return first_free - first; }
	size_type capacity() const { return cap - first; }
	void push_back(const T& item)
	{
		chk_n_alloc();
		alloc.construct(first_free++, item);
	}

	T* begin() { return first; }
	const T* begin() const { return first; }
	T* end() { return first_free; }
	const T* end() const { return first_free; }

	T& at(const size_type& i) { return *(first + i); }
	T& operator[](const size_type& i) { return *(first + i); }
	const T& operator[](const size_type& i) const { return *(first + i); }

private:
	void chk_n_alloc()
	{
		if(first_free == cap)
			reallocate();
	}

	std::pair<T*, T*> alloc_n_copy(const T* f, const T* l)
	{
		auto new_d = alloc.allocate(l - f);
		return {new_d, std::uninitialized_copy(f, l, new_d)};
	}

	void free();

	void reallocate();

	// attributes
	std::allocator<T> alloc;
	T *first, *first_free, *cap;
};

template<typename T>
Vec<T>::Vec(const Vec<T>& v)
{
	auto new_d = alloc_n_copy(v.begin(), v.end());
	first = new_d.first;
	first_free = cap = new_d.second;
}

template<typename T>
Vec<T>& Vec<T>::operator=(Vec<T> v)
{
	using std::swap;
	swap(*this, v);
	return *this;
}

template<typename T>
void Vec<T>::free()
{
	while(first_free != first)
		alloc.destroy(--first_free);
	alloc.deallocate(first, cap - first);
}

template<typename T>
void Vec<T>::reallocate()
{
	size_type new_size = size() ? size() * 3 : 1;
	auto new_d = alloc.allocate(new_size);
	auto f_free = new_d;
	for(auto t : *this)
		alloc.construct(f_free++, t);
	free();
	first = new_d;
	first_free = f_free;
	cap = first + new_size;
}

#endif // _16_16_H_
