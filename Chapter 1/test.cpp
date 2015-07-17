#include <iostream>
#include <stdlib.h>

int main()
{
	
	int *ri = (int *) malloc(sizeof(int));
	*ri = 10;
	int &test = *ri;
	std::cout << *ri << " " << test << std::endl;






	return 0;
}
