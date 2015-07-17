#include <vector>
#include <iostream>
#include <memory>
using namespace std;

typedef shared_ptr<vector<int>> vec_ptr;
vec_ptr creater(void);
void reader(istream&, vec_ptr);
void writer(ostream&, vec_ptr);

int main()
{
    vec_ptr vp(creater());

    while(1)
    {
        char c;
        reader(cin, vp);
        writer(cout, vp);
        cout << "Continue ? ";
        cin >> c;
        if(c != 'y' && c != 'Y')
            break;
    }

    return 0;
}

vec_ptr creater(void)
{
    return make_shared<vector<int>>();
}

void reader(istream& is, vec_ptr vp)
{
    int input;

    while(is >> input)
        vp->push_back(input);
    is.clear();
}

void writer(ostream& os, vec_ptr vp)
{
    for(auto x : *vp)
        cout << x << ' ';
    cout << endl;
}
