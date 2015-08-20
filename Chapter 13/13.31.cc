#include <vector>
#include "13.31.h"
#include <algorithm>
using namespace std;

int main()
{
	HasPtr a{"5"}, b{"1"}, c{"34"}, d{","};
	vector<HasPtr> vhp{a,b,c,d};
	sort(vhp.begin(), vhp.end());

	for(auto& x : vhp) x.show();
	return 0;
}
	
