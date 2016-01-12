#ifndef _17_11a_H_
#define _17_11a_H_
#include <memory>
#include <string>
#include <stdexcept>
#include <cstddef>

template <std::size_t N>
class Bits
{
public:
    // constr and destr
    Bits();
    Bits(const std::string&);
    Bits(const Bits&) = delete;
    Bits& operator=(const Bits&) = delete;
    ~Bits();

    // operations
    void set(const std::size_t&);
    void flip(const std::size_t&);
    void reset();
    void reset(const std::size_t&);
    bool test(const std::size_t&) const;
    bool operator[](const std::size_t&) const;

private:
    // private function
    void init();
    bool ops(const std::size_t&, const char&);

    // private members
    std::size_t end_pos;
    unsigned long* bits;
    std::allocator<unsigned long> alloc;
};

template <std::size_t N>
Bits<N>::Bits()
{
    init();
}

template <std::size_t N>
Bits<N>::~Bits()
{
    for(auto x = bits; x != bits + end_pos + 1; ++x)
        alloc.destroy(x);
    alloc.deallocate(bits, end_pos + 1);
}

template <std::size_t N>
Bits<N>::Bits(const std::string& s)
{
    init();
    const unsigned long mask = 1UL;
    auto curr_pos = end_pos;
    auto bit_pos = 0;
    for(auto itr = s.crbegin(); itr != s.crend(); ++itr)
    {
        if(*itr == '1')
        {
            if(bit_pos == sizeof(unsigned long) * 8)
            {
                --curr_pos;
                bit_pos = 0;
            }
            bits[curr_pos] |= (mask << bit_pos);
        }
        ++bit_pos;
    }
}

template <std::size_t N>
void Bits<N>::set(const std::size_t& n)
{
    ops(n, 's');
}

template <std::size_t N>
void Bits<N>::flip(const std::size_t& n)
{
    ops(n, 'f');
}

template <std::size_t N>
void Bits<N>::reset()
{
    for(auto itr = 0; itr != end_pos + 1; ++itr)
        bits[itr] = 0UL;
}

template <std::size_t N>
void Bits<N>::reset(const std::size_t& n)
{
    ops(n, 'r');
}

template <std::size_t N>
bool Bits<N>::test(const std::size_t& n) const
{
    return ops(n, 't');
}

template <std::size_t N>
bool Bits<N>::operator[](const std::size_t& n) const
{
    return const_cast<Bits<N>&>(*this).ops(n, 't');
}

template <std::size_t N>
void Bits<N>::init()
{

    auto size = N / sizeof(unsigned long) * 8 + 1;
    bits = alloc.allocate(size);
    for(auto x = bits; x != bits + size; ++x)
        *x = 0UL;
    end_pos = size - 1;
}

template <std::size_t N>
bool Bits<N>::ops(const std::size_t& n, const char& flg)
{
    const unsigned long mask = 1UL;
    auto curr_pos = end_pos;
    auto bit_pos = n;
    auto b_length = sizeof(unsigned long) * 8;
    while(bit_pos >= b_length)
    {
        --curr_pos;
        bit_pos -= b_length;
    }
    switch(flg)
    {
    case 's':
        bits[curr_pos] |= (mask << bit_pos);
        break;
    case 'f':
        bits[curr_pos] ^= (mask << bit_pos);
        break;
    case 'r':
        bits[curr_pos] &= ~(mask << bit_pos);
        break;
    case 't':
        return (bits[curr_pos] & (mask << bit_pos)) ? true : false;
    default:
        throw std::logic_error("undefined flag");
    }
    return bits[curr_pos];
}

#endif // 17_11a_H_
