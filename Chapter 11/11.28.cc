#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, std::vector<int>> map;
    std::map<std::string, std::vector<int>>::const_iterator itr = map.find("test");
}
