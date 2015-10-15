#ifndef _16_12_H_
#define _16_12_H_
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <stdexcept>

template<typename> class BlobPtr;

template<typename T>
class Blob
{
	friend class BlobPtr<T>;
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob();
	Blob(std::initializer_list<T>);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T& item) { data->push_back(item); }
	void push_back(T&& item) { data->push_back(std::move(item)); }
	void pop_back()
	{
		check(0, "pop_back on empty Blob");
		data->pop_back();
	}

	const T& back() const
	{
		check(0, "back on empty Blob");
		return data->back();
	}
	T& operator[](const size_type& i);
	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end() { return BlobPtr<T>(*this, data->size()); }
private:
	void check(const size_type& i, const std::string& s) const
	{
		if(i >= data->size())
			throw std::out_of_range(s);
	}

	std::shared_ptr<std::vector<T>> data;
};

template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template<typename T>
class BlobPtr
{
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
	using size_type = typename Blob<T>::size_type;
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T>& item, const size_type& sz = 0) : wptr(item.data), curr(sz) {}

	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return p->at(curr);
	}

	BlobPtr& operator++()
	{
		check(curr, "increment past end");
		++curr;
		return *this;
	}

	BlobPtr& operator++(int)
	{
		BlobPtr ret = *this;
		check(curr, "increment past end");
		++curr;
		return ret;
	}

	BlobPtr& operator--()
	{
		check(curr - 1, "decrement past begin");
		--curr;
		return *this;
	}

	BlobPtr& operator--(int)
	{
		BlobPtr ret = *this;
		check(curr - 1, "decrement past begin");
		--curr;
		return ret;
	}
private:
	std::shared_ptr<std::vector<T>> check(size_type loc, const std::string& s) const
	{
		if(loc < 0 || wptr.lock()->size() < loc)
			throw std::out_of_range(s);
		return wptr.lock();
	}

	std::weak_ptr<std::vector<T>> wptr;
	size_type curr;
};
	
template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template<typename T>
T& Blob<T>::operator[](const size_type& i)
{
	check(i, "subscript out of range.");
	return data->at(i);
}

template<typename T>
bool operator==(const BlobPtr<T>& ls, const BlobPtr<T>& rs)
{
	if(ls.wptr.lock() != rs.wptr.lock())
		throw std::runtime_error("pointer point to different Blobs");
	return ls.curr == rs.curr;
}

template<typename T>
bool operator!=(const BlobPtr<T>& ls, const BlobPtr<T>& rs)
{
	return !(ls == rs);
}

#endif // _16_12_H_
