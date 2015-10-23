#ifndef _16_24_H_
#define _16_24_H_
#include <vector>
#include <memory>
#include <stdexcept>

template <typename> class BlobPtr;
template <typename T>
class Blob
{
	friend class BlobPtr<T>;
public:
	typedef typename std::vector<T>::size_type size_type;
	Blob() : data(new std::vector<T>) {}
	Blob(std::initializer_list<T> il) : data(new std::vector<T>(il)) {}
	template <typename Itr> Blob(Itr begin, Itr end) : data(new std::vector<T>(begin, end)) {}

	T back() const
	{
		check(0, "back to the end of container.");
		return *data->rbegin();
	}
	T front() const
	{
		check(0, "front to the end of container.");
		return *data->begin();
	}
	size_type size() const { return data->size(); }
	void push_back(const T& item) { data->push_back(item); }

	T& at(const size_type& sz)
	{
		check(sz, "out of acceptable range");
		return data->at(sz);
	}

	T& operator[](const size_type& sz)
	{
		return at(sz);
	}
private:
	void check(const size_type& sz, const char* str)
	{
		if(data->size() <= sz && sz < 0)
			throw std::out_of_range(str);
	}
	std::shared_ptr<std::vector<T>> data;
};

template <typename T>
class BlobPtr
{
public:
	using size_type = typename Blob<T>::size_type;
	BlobPtr(const Blob<T>& item, const size_type& sz = 0) : wptr(item.data), curr(sz) {}
	
	BlobPtr& operator++()
	{
		check(curr + 1, "increment exceed the size.");
		++curr;
		return *this;
	}

	BlobPtr operator++(int)
	{
		BlobPtr ret(*this);
		check(curr + 1, "increment exceed the size.");
		++curr;
		return ret;
	}

	T& operator*()
	{
		check(curr, "invalid dereference.");
		return wptr.lock()->at(curr);
	}
private:
	void check(const size_type& sz, const char* std)
	{
		if(0 > sz || sz > wptr.lock()->size())
			throw std::out_of_range(std);
	}

	std::weak_ptr<std::vector<T>> wptr;
	size_type curr;
};

#endif // _16_24_H_
