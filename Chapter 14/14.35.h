#ifndef _14_35_h_
#define _14_35_h_
#include <iostream>
#include <string>

class GetString
{
public:
	std::string operator()(std::istream& is)
	{
		std::string input;

		std::getline(is, input);
		if(!is)
			input = std::string();
		return input;
	}
}

#endif // _14_35_h_
