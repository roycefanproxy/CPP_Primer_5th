#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vi(10, 20);
    while(auto x : vi)
        cout << x << endl;

    return 0;
}
