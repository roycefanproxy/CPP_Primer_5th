#include <vector>
#include <cstring>
#include "13.44.h"
using namespace std;

int main()
{
	vector<String> vs;
	char ctemplate[10] = "Test ";
	for(char i = 0; i != 20; ++i)
	{
		ctemplate[5] = '0' + i + 1;
		vs.push_back(ctemplate);
	}
	for(auto& s : vs)
		print(s);

	return 0;
}
