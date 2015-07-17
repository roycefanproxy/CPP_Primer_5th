#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> conta(10);
    int temp;

    for(auto i = conta.begin(); i != conta.end(); i++)
    {
        cin >> temp;
        *i = temp * 2;
    }
    for(auto x : conta)
        cout << x << endl;

    cout << "Done." << endl;

    return 0;
}
