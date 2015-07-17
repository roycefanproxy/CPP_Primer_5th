#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<char> vc{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string s(vc.cbegin(), vc.cend());

    s.reserve(200);
    cout << s << endl;
    cout << s.size() << ' ' << s.capacity() << ' ' << endl;
}
