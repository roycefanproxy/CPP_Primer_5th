#ifndef _StrBlob_h_
#define _StrBlob_h_
#include <vector>
#include <string>
#include <exception>
#include <memory>

class StrBlobPtr;

class StrBlob
{
    friend StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> values) : data(std::make_shared<std::vector<std::string>>(values)) {}

    size_type size(void);

    void pop_back(void)
    {
        data->pop_back();
    }

    void push_back(std::string s) { data->push_back(s); }

    std::string& back(void)
    {
        check(1, "No value in container.");
        return data->back();
    }
    std::string back(void) const;

    std::string& front(void)
    {
        check(1, "No value in container.");
        return data->front();
    }
    std::string front(void) const
    {
        check(1, "No value in container.");
        return data->front();
    }

    bool empty(void) const;
private:
    void check(const int, const std::string&) const;
    std::shared_ptr<std::vector<std::string>> data;
};

std::string StrBlob::back(void) const
{
    check(1, "No value in container.");
    return data->back();
}

StrBlob::size_type StrBlob::size(void)
{
    return data->size();
}

void StrBlob::check(const int i, const std::string& s) const
{
    if(i > data->size()) throw std::out_of_range(s);
}

bool StrBlob::empty(void) const { return data->empty(); }

class StrBlobPtr
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlobPtr(void) = default;
    StrBlobPtr(StrBlob& item, size_type sz = 0) : wptr(item.data) {}
    StrBlobPtr& incre(void);
    std::string& deref(void) const;

private:
    std::shared_ptr<std::vector<std::string>> check(size_type, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_type sz = 0;
};

StrBlobPtr& StrBlobPtr::incre(void)
{
    check(sz, "Increment past end of the range.");
    ++sz;
    return *this;
}

std::string& StrBlobPtr::deref(void) const
{
    return (*check(sz, "Dereference past end."))[sz];
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
#endif // _StrBlob_h_
