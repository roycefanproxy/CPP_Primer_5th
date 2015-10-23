#ifndef _16_21_H_
#define _16_21_H_
#include <iostream>
#include <memory>

class PtrDeleter
{
public:
	PtrDeleter(std::ostream& s = std::cerr) : os(std::cerr) {}
	template<typename T> void operator()(const T* p) { os << "Deleting pointer." << std::endl; delete p; }
private:
	std::ostream& os;
};

#endif // _16_21_H_
