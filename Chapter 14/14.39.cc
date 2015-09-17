#include <iostream>
using namespace std;

struct Pair
{
	unsigned int less_10;
	unsigned int more_10;
};

class WordCounter
{
public:
	Pair operator()(std::istream& is)
	{
		Pair pair{0, 0};
		string temp;
		while(is >> temp && temp != "q")
		{
			if(temp.size() < 11)
				++pair.less_10;
			else
				++pair.more_10;
		}
		return pair;
	}
};

int main()
{
	WordCounter wc;

	auto result = wc(cin);
	cout << "Less than 10 : " << result.less_10 << endl;
	cout << "More than 10 : " << result.more_10 << endl;

	return 0;
}

