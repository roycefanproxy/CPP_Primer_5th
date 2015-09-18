#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

struct Divider
{
	int operator()(int a, int b) { return a / b; }
};

int main()
{
	map<string, function<int(int, int)>> cal{{"+", [](int a, int b) { return a + b; }},
								{"-", minus<int>()},
								{"*", multiplies<int>()},
								{"/", Divider()},
								{"%", modulus<int>()}};
	cout << cal["-"](7, 15) << endl;
	cout << cal["+"](5, 18) << endl;
	cout << cal["/"](174, 17) << endl;
	cout << cal["%"](176, 3) << endl;
	cout << cal["*"](16,2) << endl;

	return 0;
}
