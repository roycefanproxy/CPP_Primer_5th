#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1, v2(10), v3(10, 42), v4{10}, v5{10, 42};
    vector<string> v6{10}, v7{10, "hi"};

    cout << "v1 : " << v1.size() << endl;
    for(auto i = v1.begin(); i != v1.end(); i++)
        cout << *i << endl;
    cout << "v2 : " << v2.size() << endl;
    for(auto i = v2.begin(); i != v2.end(); i++)
        cout << *i << endl;
    cout << "v3 : " << v3.size() << endl;
    for(auto i = v3.begin(); i != v3.end(); i++)
        cout << *i << endl;
    cout << "v4 : " << v4.size() << endl;
    for(auto i = v4.begin(); i != v4.end(); i++)
        cout << *i << endl;
    cout << "v5 : " << v5.size() << endl;
    for(auto i = v5.begin(); i != v5.end(); i++)
        cout << *i << endl;
    cout << "v6 : " << v6.size() << endl;
    for(auto i = v6.cbegin(); i != v6.end(); i++)
        cout << * i << endl;
    cout << "v7 : " << v7.size() << endl;
    for(auto i = v7.cbegin(); i != v7.end(); i++)
        cout << *i << endl;

    return 0;
}
