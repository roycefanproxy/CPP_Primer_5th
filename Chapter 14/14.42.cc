#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	using placeholders::_1;
	vector<int> vi{1534, 415, 45, 342, 617, 4613, 6246, 616, 95, 4, 546, 45672, 552, 113, 826, 58, 757, 86568, 7365};
	cout << "Part a :\n";
	cout << count_if(vi.begin(), vi.end(), bind(greater<int>(), _1, 1024)) << endl;
	vector<string> vs{"pooh", "pooh", "pooh", "pooh", "pooh", "pooh", "pooh", "tes", "pooh", "pooh", "pooh", "Pooh"};
	cout << "Part b :\n";
	cout << *find_if_not(vs.cbegin(), vs.cend(), bind(equal_to<string>(), _1, "pooh")) << endl;
	cout << "Part c :\n";
	transform(vi.begin(), vi.end(), vi.begin(), bind(multiplies<int>(), _1, 2));
	for(auto& i : vi)
		cout << i << endl;

	return 0;
}

