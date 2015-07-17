#include <iostream>
using namespace std;

int main()
{
    int a(0), e(0), i(0), o(0), u(0);
    string input;

    while(cin >> input)
        for(auto c : input)
        {
            if(c == 'a')
                a++;
            else if(c == 'e')
                e++;
            else if(c == 'i')
                i++;
            else if(c == 'o')
                o++;
            else if(c == 'u')
                u++;
        }

    cout << "Result : \na : " << a << "\ne : " << e << "\ni : " << i << endl;
    cout << "o : " << o << "\nu : " << u << endl;

    return 0;
}
