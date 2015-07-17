#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main()
{
    ifstream fs("11.20.cc");
    string buff;
    map<string, unsigned> msu;
    map<string, unsigned>::iterator itr;

    if(!fs.is_open())
        cerr << "failed to open file." << endl;
    while(fs >> buff)
    {
        if((itr = msu.find(buff)) == msu.end())
            msu.insert({buff, 1});
        else
            ++itr->second;
    }
    for(auto& x : msu)
        cout << x.first << ' ' << x.second << endl;

}
