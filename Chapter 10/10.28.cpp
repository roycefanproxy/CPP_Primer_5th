#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    vector<int> source{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> tar1, tar3;
    deque<int> tar2;

    auto itr1 = back_inserter(tar1);
    auto itr2 = front_inserter(tar2);
    auto itr3 = inserter(tar3, tar3.begin());
    for(auto x : source)
    {
        itr1 = x;
        itr2 = x;
        itr3 = x;
    }
    for(int i = 0; i < 9; ++i)
        cout << tar1[i] << ' ' << tar2[i] << ' ' << tar3[i] << endl;

    return 0;
}
