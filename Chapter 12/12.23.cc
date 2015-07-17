#include <iostream>
#include <string>
#include <memory>
#include <cstring>
using namespace std;

int main()
{
    char word[2][50];
    unique_ptr<char []> result(new char[100]);

    for(int i = 0; i != 2; ++i)
        cin >> word[i];
    for(int i = 0,c = 0; i != 2; ++i)
    {
        for(int p = 0; p != strlen(word[i]); ++p)
            result[c++] = word[i][p];
        if(i == 0)
            result[c++] = ' ';
    }
    cout << "C style string:\n";
    cout << result.release() << endl;

    string str[]{word[0], word[1]};
    unique_ptr<string> strp(new string());
    *strp = str[0];
    strp->push_back(' ');
    *strp += str[1];

    cout << "C++ style string:\n" << *strp << endl;

    return 0;
}
