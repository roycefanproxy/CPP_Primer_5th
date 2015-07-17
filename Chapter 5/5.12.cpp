#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string input;
    int a(0), e(0), i(0), o(0), u(0), num(0), nl(0), tab(0), space(0);
    int ff(0), fl(0), fi(0);

    while(getline(cin, input))
    {
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
            case '\t':
                tab++;
                break;
            case ' ':
                space++;
                break;
            case 'f':
                if(*(c + 1) == 'i')
                    fi++;
                else if(*(c + 1) == 'l')
                    fl++;
                else if(*(c + 1) == 'f')
                    ff++;
                break;
            default:
                if(isdigit(*c))
                    ++num;
            }
        nl++;
    }

    cout << "Result :\na : " << a << "\ne : " << e << "\ni : " << i << endl;
    cout << "o : " << o << "\nu : " << u << endl;
    cout << "space : " << space << endl;
    cout << "tab : " << tab << "\nnumber : " << num << "\nnewline : " << nl;
    cout << endl;
    cout << "ff : " << ff << endl;
    cout << "fl : " << fl << "\nfi : " << fi << endl;

    return 0;
}


