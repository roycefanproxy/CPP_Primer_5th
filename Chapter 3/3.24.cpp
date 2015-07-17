#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> conta;
    int temp;
    while(cin >> temp)
        conta.push_back(temp);
    for(auto b = conta.cbegin(), e = conta.cend() - 1; b < e; b++, e--)
        cout << *b + *e << endl;
}
