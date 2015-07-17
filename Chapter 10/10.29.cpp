#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream fs("Sales_Item.h");
    istream_iterator<string> ifsi(fs), eof;
    vector<string> vs;
    //string s;
    while(ifsi != eof)
    //while(getline(fs, s))
        vs.push_back(*ifsi++);
        //vs.push_back(s);
    for(auto& x : vs)
        cout << x << ends;
}
