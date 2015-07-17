#include <iostream>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    ifstream ifs("ifs.txt", ifstream::in);
    ofstream ofs1("ofs1.txt", ofstream::out), ofs2("ofs2.txt", ofstream::out);

    if(!ifs.is_open())
    {
        srand(static_cast<unsigned int>(time(0)));
        ofstream writter("ifs.txt", ofstream::out);
        for(int i = 0; i != 20; ++i)
            writter << rand() << ' ';
        writter.close();
        ifs.open("ifs.txt", ifstream::in);
    }

    istream_iterator<int> isi(ifs), eof;
    ostream_iterator<int> osi1(ofs1, " "), osi2(ofs2, "\n");

    while(isi != eof)
    {
        if(*isi % 2)
            *osi1++ = *isi++;
        else
            *osi2++ = *isi++;
    }

    ifs.close();
    ofs1.close();
    ofs2.close();

    return 0;
}

