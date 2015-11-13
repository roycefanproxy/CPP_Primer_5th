#ifndef _16_12_H_
#define _16_12_H_
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include "16.28.h"

template<typename T>
class Blob
{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	typedef typename std::vector<T>::iterator itr;

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
	itr begin() { return data->begin(); }
	itr end() { return data->end(); }
private:
	void check(const size_type& i, const std::string& s) const
	{
		if(i >= data->size())
			throw std::out_of_range(s);
	}

	S_ptr<std::vector<T>> data;
};

template<typename T>
Blob<T>::Blob() : data(new std::vector<T>) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(new std::vector<T>(il)) {}

template<typename T>
T& Blob<T>::operator[](const size_type& i)
{
	check(i, "subscript out of range.");
	return data->at(i);
}

#endif // _16_12_H_
