#include <iostream>
#include <fstream>
#include <sstream>
#include "StrBlob.h"
using namespace std;

int main()
{
    ifstream fs("StrBlob.h");
    string buff;
    StrBlob vec;

    if(!fs.is_open())
        return 1;
    while(getline(fs, buff))
        vec.push_back(buff);
    fs.close();
    StrBlobPtr vec_ptr(vec);
    try
    {
        while(1)
        {
            //stringstream ss(vec_ptr.deref());
            //while(ss >> buff)
            //    cout << buff << '\n';
            cout << vec_ptr.deref() << endl;
            vec_ptr.incre();
        }
    }
    catch(out_of_range ex)
    {
        cout << ex.what() << '\n';
        cout << "That means done." << endl;
    }
}
