#ifndef _13_26_h_
#define _13_26_h_
#include <string>
#include <vector>
#include <memory>
#include <exception>

class StrBlobPtr;

class StrBlob
{
	friend StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string> values) :
		data(std::make_shared<std::vector<std::string>>(values)) {}
	StrBlob(const StrBlob& sb) { data = std::make_shared<std::vector<std::string>>(*sb.data); }
	StrBlob& operator=(const StrBlob& sb) { data = std::make_shared<std::vector<std::string>>(*sb.data); }
	size_type size();

	void pop_back() { data->pop_back(); }
	void push_back(std::string s) { data->push_back(s); }
	std::string& back() { check(1, "No value in container."); data->back(); }
	std::string& front() { check(1, "No value in container."); data->front(); }
	bool empty() const { return data->empty(); }

private:
	void check(const int, const std::string&) const;
	std::shared_ptr<std::vector<std::string>> data;
};

void StrBlob::check(const int i, const std::string& s) const
{
	if(i > data->size()) throw std::out_of_range(s);
}

class StrBlobPtr
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlobPtr() = delete;
	StrBlobPtr(StrBlob& item, size_type sz = 0) : wptr(item.data), size(sz) {}
	StrBlobPtr& incre(void) const;
	std::string& deref(void) const;

private:
	std::shared_ptr<std::vector<std::string>> check(size_type, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	mutable size_type size;
};

StrBlobPtr& StrBlobPtr::incre(void) const
{
	check(size, "Increment past end of the range.");
	++size;

	return const_cast<StrBlobPtr&>(*this);
}

std::string& StrBlobPtr::deref(void) const
{
	return (*check(size, "Dereference past end."))[size];
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_type sz, const std::string& s) const
{
	auto ptr = wptr.lock();
	if(!ptr)
		throw std::runtime_error("Unbounded StrBlobPtr.");
	if(sz >= ptr->size())
		throw std::out_of_range(s);

	return ptr;
}

#endif //_13_26_h_
