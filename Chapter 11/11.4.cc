#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
using std::string; using std::map; using std::cin; using std::cout; using std::endl;

int main()
{
    map<string, size_t> mss;
    string input;

    while(cin >> input)
    {
        for(char& c : input)
            c = tolower(c);
        input.erase(std::find_if(input.begin(), input.end(), [] (const char c) -> bool { return ispunct(c);}), input.end());
        ++mss[input];
    }

    for(auto itr = mss.crbegin(); itr != mss.crend(); ++itr)
        cout << itr->first << ' ' << itr->second << endl;

    return 0;

}
