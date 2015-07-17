#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    vector<int> test;

    srand((unsigned) time(0));

    for(int i = 0; i < 100; i++)
        test.push_back(rand());
    decltype(test.begin()) i, j, e = test.end();

    int gap = 1, temp;
    const int N = test.size();
    while(gap < N/3) gap = gap * 3 + 1;

    while(gap >= 1)
    {
        for(i = test.begin() + gap; i != e; i += gap)
        {
            temp = *i;
            j = i - gap;
            while(j >= test.begin() && *j < temp)
            {
                *(j + gap) = *j;
                j -= gap;
            }
            *(j + gap) = temp;
        }
        gap /= 3;
    }
    for(int x = 1; x <= 100; x++)
    {
        cout << test[x];
        if(x % 10 == 0)
            cout << endl;
    }
}
