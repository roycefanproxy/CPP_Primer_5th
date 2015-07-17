#include <iostream>
#include <vector>
#include <new>
using namespace std;

vector<int>* vec_creater(void);
void reader(istream&, vector<int>*);
void writer(ostream&, vector<int>*);

int main()
{
    auto v_ptr(vec_creater());
    char i;
    while(1)
    {
        reader(cin, v_ptr);
        writer(cout, v_ptr);
        cout << "Continue ? ";
        cin.clear();
        cin >> i;
        if(i != 'y' && i != 'Y') break;
    }
    delete v_ptr;

    return 0;
}

vector<int>* vec_creater(void)
{
    return new vector<int>;
}

void reader(istream& is, vector<int>* vip)
{
    int input;

    while(is >> input)
        vip->push_back(input);
}

void writer(ostream& os, vector<int>* vip)
{
    for(auto x : *vip)
        cout << x << ' ';
    cout << endl;
}
