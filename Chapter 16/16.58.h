#ifndef _16_58_H_
#define _16_58_H_
#include <utility>
#include <memory>

template <typename T>
class Vec
{
public:
    typedef size_t size_type;
    Vec() : first(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(std::initializer_list<T> il) { alloc_n_copy(il.begin(), il.end()); }
    Vec(const Vec<T>& rhs) { alloc_n_copy(rhs.begin(), rhs.end()); }
    Vec& operator=(const Vec<T>&);
    ~Vec()
    {
        free();
    }

    size_type size() const { return first_free - first; }
    size_type capacity() const { return cap - first; }
    bool empty() const { return first; }

    template <typename VT>
    void push_back(const VT& arg)
    {
        chk_n_alloc();
        allocator.construct(first_free++, arg);
    }

    template <typename VT>
    void push_back(VT&& arg)
    {
        chk_n_alloc();
        allocator.construct(first_free++, std::move(arg));
    }

    template <typename... Args>
    void emplace_back(Args&&... args)
    {
        chk_n_alloc();
        allocator.construct(first_free++, std::forward<Args>(args)...);
    }

    T* begin() const { return first; }
    T* end() const { return first_free; }
    T& at(size_type pos) const { return *(first_free + pos); }
    T& operator[](size_type pos)
    {
        return const_cast<T&>(const_cast<const T&>(*this)[pos]);
    }
    const T& operator[](size_type pos) const
    {
        return *(first + pos);
    }

private:
    void chk_n_alloc()
    {
        if(first_free == cap)
            reallocate();
    }

    void alloc_n_copy(T* beg, T* end)
    {
        auto d_s = end - beg;
        auto new_d = allocator.allocate(end - beg);
        first = new_d;
        first_free = std::uninitialized_copy(beg, end, new_d);
        cap = first + d_s;
    }

    void reallocate()
    {
        auto new_size = size() ? size() * 3 : 2;
        auto new_d = allocator.allocate(new_size);
        auto temp_last = new_d;
        auto b = first;
        while(b != end())
            allocator.construct(temp_last++, std::move(*b++));
        free();
        first = new_d;
        first_free = temp_last;
        cap = first + new_size;
    }

    void free()
    {
        while(first_free != first)
            allocator.destroy(--first_free);
        allocator.deallocate(first, cap - first);
    }

    // private member data
    std::allocator<T> allocator;
    T *first, *first_free, *cap;
};

#endif // _16_58_H_
