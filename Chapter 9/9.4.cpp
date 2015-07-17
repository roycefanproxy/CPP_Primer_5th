#include <iostream>
#include <vector>
#include <cstdlib>
#include <deque>
#include <ctime>
using namespace std;

bool is_found(vector<int>::const_iterator, vector<int>::const_iterator, int);

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));
    vector<int> container;
    int input;

    for(int i = 0; i < 30; ++i)
        container.emplace_back(rand());

    cout << "Enter the value that you want to find :" << ends;
    while(cin >> input)
    {
        if(is_found(container.cbegin(), container.cend(), input))
            cout << input << " is found." << endl;
        else
            cout << input << " is not in the vector<int>." << endl;
    }
    cout << "Done." << endl;

    return 0;
}

bool is_found(vector<int>::const_iterator begin, decltype(begin) end, int n)
{
    for(auto x = begin; x != end; ++x)
        if(*x == n)
            return true;

    return false;
}
