#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

bool divisible(const int&, const int&);
int main()
{
	using std::placeholders::_1;
	std::vector<int> vi{2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int input;
	std::modulus<int> mod;
	std::cin >> input;
	// auto modul = [&] (int& i) { return mod(input, i) ? false : true; };
	
	std::cout << std::any_of(vi.begin(), vi.end(), std::bind(divisible, input, _1)) << std::endl;

	return 0;
}

bool divisible(const int& input, const int& di)
{
	static std::modulus<int> mod;

	return mod(input, di) == 0;
}
