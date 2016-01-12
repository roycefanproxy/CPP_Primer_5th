#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    bitset<32> bin_arr;
    const int fibonacci[] = {1, 2, 3, 5, 8, 13, 21};
    for(auto itr = begin(fibonacci); itr != end(fibonacci); ++itr)
        bin_arr.set(*itr);
    for(int i = 0; i != 32; ++i)
        if(!bin_arr[i])
            bin_arr.set();

    cout << bin_arr << endl;

    return 0;
}
