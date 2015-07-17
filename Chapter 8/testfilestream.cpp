#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct S_D
{
    string bookNo;
    unsigned unit_sold;
    double revenue;
};

istream& read(istream&, S_D&);
ostream& print(ostream&, const S_D&);
S_D add(const S_D&, const S_D&);

int main(void)
{
    int input;
    cout << "1 : enter value" << flush;
    cout << "\t2 : print" << endl;
    while(cin >> input)
    {
        if(input == 1)
        {
            S_D data;
            ofstream file("textfile.txt", ofstream::app);
            if(file)
            {
                cout << "Enter the value." << endl;
                while(read(cin, data))
                {
                    print(file, data);
                }
                file.close();
            }
            else
                cerr << "Fail to open file." << endl;
        }
        else
        {
            ifstream file("textfile.txt");
            S_D curr, trans;
            if(file)
            {
                if(read(file, curr))
                {
                    while(read(file, trans))
                    {
                        if(curr.bookNo == trans.bookNo)
                            curr = add(curr, trans);
                        else
                        {
                            print(cout, curr);
                            curr = trans;
                        }
                    }
                    print(cout, curr);
                }
                else
                {
                    cerr << "No data found." << endl;
                }
                file.close();
            }
        }
        cout << "1 : enter value" << flush;
        cout << "\t2 : print" << endl;
    }
    return 0;
}

istream& read(istream& is, S_D& item)
{
    double price;
    is >> item.bookNo >> item.unit_sold >> price;
    item.revenue = price * (int) item.unit_sold;

    return is;
}

ostream& print(ostream& os, const S_D& item)
{
    os << item.bookNo << " " << item.unit_sold << " " << item.revenue / item.unit_sold << endl;

    return os;
}

S_D add(const S_D& item1, const S_D& item2)
{
    S_D ret_val{item1.bookNo, item1.unit_sold + item2.unit_sold, item1.revenue + item2.revenue};

    return ret_val;
}
