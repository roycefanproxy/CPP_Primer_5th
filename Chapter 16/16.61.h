#include <memory>

template <class T, typename... Args>
std::shared_ptr<T> make_S(Args&&... args)
{
    return 
