#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> conta;
    int temp;

    while(cin >> temp)
        conta.push_back(temp);
    for(int i = 0; i < conta.size() / 2; i++)
        cout << conta[i] + conta[conta.size() - i - 1] << endl;
    cout << "Done." << endl;

    return 0;
}
