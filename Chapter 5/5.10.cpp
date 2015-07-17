#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string input;
    int a(0), e(0), i(0), o(0), u(0);

    while(cin >> input)
        for(auto c = input.cbegin(); c != input.cend(); c++)
            switch(tolower(*c))
            {
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            }

    cout << "Result :\na : " << a << "\ne : " << e << "\ni : " << i << endl;
    cout << "o : " << o << "\nu : " << u << endl;

    return 0;
}
