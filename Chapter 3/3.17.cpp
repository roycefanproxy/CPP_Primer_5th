#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    vector<string> stream;
    string temp;

    while((cin >> temp) && temp[0] != '\n')
        stream.push_back(temp);
    for(string &entry : stream)
        for(auto &c : entry)
            c = toupper(c);
    for(int i = 1; i <= stream.size(); i++)
    {
        cout << stream[i-1] << " ";
        if(i % 8 == 0)
            cout << endl;
    }

    return 0;

}
