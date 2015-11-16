#include <iostream>

template <typename T1, typename T2>
auto sum(const T1& a, const T2& b) -> decltype(a + b) { return a + b; } 

int main()
{
	using namespace std;

	cout << sum(15L, 1024) << endl;

	return 0;
}
