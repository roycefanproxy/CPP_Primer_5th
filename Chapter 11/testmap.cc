#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, string> mss;
    string input1, input2;

    while((cin >> input1 >> input2) && input1 != "done")
        mss[input1] = input2;

    for(auto itr = mss.cbegin(); itr != mss.cend(); ++itr)
        cout << itr->first << ' ' << itr->second << endl;
    cin >> input1;
    cout << mss[input1] << endl;

    return 0;
}
