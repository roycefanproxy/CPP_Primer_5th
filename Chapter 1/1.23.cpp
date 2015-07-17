#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item input, storage;
	int count = 0;

	if(std::cin >> storage)
	{
		while(std::cin >> input)
		{
			
			if(input.isbn() == storage.isbn())
			{
				count++;
			}
			else
			{
				std::cout << "the " << storage.isbn() << " occured " << count << " times. " << std::endl;
				count = 1;
				storage = input;
			}
		}
	}
	std::cout << "Done." << std::endl;

	return 0;
}


