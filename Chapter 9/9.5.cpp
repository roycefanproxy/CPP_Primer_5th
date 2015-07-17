#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int>::iterator is_found(vector<int>::iterator, vector<int>::iterator, int);

int main(void)
{
    srand((unsigned) time(0));

    vector<int> container;
    auto input(0);

    for(int i = 0; i != 30; ++i)
        container.emplace_back(rand());
    cout << "Enter a number to find : " << flush;
    while(cin >> input)
    {
        auto index = is_found(container.begin(), container.end(), input);
        if(index != container.end())
            cout << "The index of input is " << index - container.cbegin() << '.' << endl;
        else
            cout << "value not found." << endl;
        cout << "Enter a number to find : " << flush;
    }

    cout << "Done." << endl;

    return 0;
}

vector<int>::iterator is_found(vector<int>::iterator begin, vector<int>::iterator end, int n)
{
    auto x = begin;
    while(x != end && *x != n)
        ++x;
    return x != end ? x : end;


}
