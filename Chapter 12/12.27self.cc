#include "MyTextQuery.h"
#include <fstream>

void ReadQuery(std::istream& stream);
std::ostream& print(std::ostream& os, QueryResult result);
int main()
{
    std::ifstream file("12.27.cc");

    if(file.is_open())
        ReadQuery(file);
    return 0;
}

void ReadQuery(std::istream& stream)
{
    TextQuery file(stream);
    std::string input;

    std::cout << "Enter the word for checking : " << std::flush;
    while(1)
    {
        if(!(std::cin >> input) || input == "q")
            break;
        print(std::cout, file.query(input)) << std::endl;
    }
}

std::ostream& print(std::ostream& os, const QueryResult result)
{
    os << "Occurred " << result.occurence << " time(s).\n" << std::endl;

    int i = 0;
    for(auto itr : *result.l_n)
        os << '(' << itr << ')' << (*result.file_content)[itr] << std::endl;

    return os;
}
